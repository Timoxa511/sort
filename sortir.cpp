//sorts_pack
#include "TXLib.h"         //math.h, .....
#include "homemade_int.h"
#include "templates.h"     //homemade_int.h

#include <windows.h>
#include <stdio.h>


#include "../sfml_gui/Alib.h" // SFML/graphics.hpp ..

#define id(n) n     //TODO

//#define PrintfDebug



//{Protoypes-------------------------------------------------------------------

struct FnStats
    {
    const char* name_;
    void        (*fn_) (int_t arr [], size_t arrsz);

    std::vector<int> comps_;
    std::vector<int> swaps_;
    };

class Resources
    {
    public:
    std::vector <AL::Sprite>  sprites_;
    std::vector <sf::Texture> textures_;
    //---------------------

    Resources (std::initializer_list <const char*> fileNames);


    };

bool BubbleSortTest ();

namespace Global
{
int SIZE = 100;
size_t STEP = 2;
Vector WinSize (1000, 1000);
Resources* Res = nullptr;
double XSCALE  = 6;
//sf::RenderWindow* window = nullptr;
}

//}
//-----------------------------------------------------------------------------


//=============================================================================



//{algorithms------------------------------------------------------------------



//{fns-------------------------------------------------------------------------
template <typename T>    //template for sync with int_t for cmp counter
void BubbleSort (T arr [], size_t arrsz)
    {
    for (int i = 0; i < arrsz; i++)
        {
        bool sorted = true;
        for (int j = 0; j < arrsz - 1 - i; j++)
            {
            assert (0 <= j && j < arrsz);
            assert (0 <= j + 1 && j + 1 < arrsz);

            if (arr[j] > arr[j + 1])  { Swap (arr[j], arr[j + 1]); sorted = false; }
            }
        if (sorted) break;
        }
    }

//-----------------------------------------------------------------------------
template <typename T, int N>               //inline means substitution fn in compiling time (for speed) (good compilers and optimizers do it themselves)
inline void BubbleSort (T (&arr) [N])     //cause arrays are references (shock content!) and in template fns types of the prms should be given correctly
    {
    BubbleSort (arr, N);
    }



//-----------------------------------------------------------------------------
#define check(f_id)                                     \
({int id = f_id; assert (0 <= id && id < arrsz); id;})       //gcc spec

template <typename T>
void SelectSort (T arr [], size_t arrsz)
    {
    for (int i = arrsz - 1; i >= 0; i--)
        {
        //Printf (arr, arrsz, -1, MaxElemNumber(arr, i + 1), i + 1, true, "check ");
        Swap (arr [ check(MaxElemNumber(arr, i + 1)) ], arr[ check(i) ]);
        }
    }

//-----------------------------------------------------------------------------
template <typename T>
int MaxElemNumber (const T arr [], size_t arrsz)
    {
    int maxId = 0;
    for (int i = 1; i < arrsz; i++)
        {
        if (arr[ check(i) ] > arr[ check(maxId) ]) maxId = i;
        }
    return maxId;
    }

//-----------------------------------------------------------------------------

template <typename T, int N>
inline void SelectSort (T (&arr) [N])
    {
    SelectSort (arr, N);
    }

//}
//-----------------------------------------------------------------------------


//{unittests-------------------------------------------------------------------

#define unitTest(initializer_list, expected, swaps, comps)                                                                                        \
    {                                                                                                                                             \
    int_t experimentalMouse [] = initializer_list;                                                                                                \
    int_t::resetCounters ();                                                                                                                      \
    BubbleSort (experimentalMouse);                                                                                                               \
    if (ArrCmp(experimentalMouse, expected) && int_t::swaps_ == swaps && int_t::comps_ == comps)  {$sg; Printf (experimentalMouse, 1, 3, 5, true, "uTest");}     \
                                                                                             else {$sr; Printf (experimentalMouse, 1, 3, 5, true, "uTest");}     \
    printf ("%d, %d\n", int_t::swaps_, int_t::comps_);                                                                                            \
    }

#define _ ,

bool BubbleSortTest ()
    {

    unitTest ({1t}, {1t}, 0, 0);

    unitTest ({1t _ 0t}, {0t _ 1t}, 1, 1);

    unitTest ({4t _ 1t _ 3t}, {1t _ 3t _ 4t}, 2, 3);

    unitTest ({1t _ 2t _ 3t _ 4t _ 5t _ 6t}, {1t _ 2t _ 3t _ 4t _ 5t _ 6t}, 0, 5);

    unitTest ({1t _ 3t _ 2t _ 4t _ 5t _ 6t}, {1t _ 2t _ 3t _ 4t _ 5t _ 6t}, 1, 9);


    }

#undef unitTest

//}
//-----------------------------------------------------------------------------



//}
//-----------------------------------------------------------------------------


//{classes-------------------------------------------------------------------


//{Resources::-----------------------------------------------------------------

Resources::Resources (std::initializer_list <const char*> fileNames) :
    sprites_  (),
    textures_ (fileNames.size())
    {
    int i = 0;
    for (auto& fileName : fileNames)
        {
        textures_.at(i).loadFromFile (fileName);

        AL::Sprite sprite ("res" + std::to_string(i));
        sprite.setTexture (&textures_.at(i));
        sprite.setRenderWindow (AL::Global::RenderWindow);

        sprites_.push_back (sprite);

        i++;
        }
    }

//}
//-----------------------------------------------------------------------------


//}
//-----------------------------------------------------------------------------


//{Functions-------------------------------------------------------------------
void fullFnStats (FnStats *stats)
    {

    int_t experimentalMouse [Global::SIZE] = {};

    for (int i = Global::STEP; i <= Global::SIZE; i += Global::STEP)
        {
        int_t::resetCounters ();

        FillArr       (experimentalMouse, i);
        stats->fn_    (experimentalMouse, i);

        stats->comps_.push_back (int_t::comps_);
        stats->swaps_.push_back (int_t::swaps_);
        }

    }



//-----------------------------------------------------------------------------
using sort_fn_t = void (int_t arr [], size_t arrsz);
std::vector <FnStats> mltFullFnStats (std::initializer_list <FnStats> list)
    {
    std::vector<FnStats> mltStats;

    for (auto& stats : list)
        {
        mltStats.push_back (stats);
        fullFnStats (&mltStats.back());
        }
    return mltStats;
    }



//-----------------------------------------------------------------------------
void Test ()
    {
    const size_t n = 10;
    int_t arr [n] = {};

    FillArr (arr, n);
    Printf  (arr, n, 1, 3, 4, true, "zapolnenijje na %u elems", n);

    SelectSort (arr);
    Printf  (arr, 1, 4, 6, true, "sortirovka");

    }



//-----------------------------------------------------------------------------
bool WindowIsOpen()
    {
    sf::Event event;
    while (AL::Global::RenderWindow->pollEvent (event) )
        if (event.type == sf::Event::Closed) return false;
    return true;
    }



//-----------------------------------------------------------------------------
void Dump (const std::vector<FnStats> &stats)
    {
    if (&stats == nullptr) {printf("null_param"); return;}

    for (int i = 0; i < stats.size(); i++)
        for (int j = 0; j < Global::SIZE; j++)
            printf ("%s : comps[%d], swaps[%d]\n", stats.at(i).name_, stats.at(i).comps_.at(j), stats.at(i).swaps_.at(j));
    }



//-----------------------------------------------------------------------------
void drawGraph (Vector pos, std::vector<int> dataY, AL::Sprite bullet)
    {

    //TODO findMaxElem


    for (int i = 0; i < dataY.size(); i++)
        {
        Draw (bullet, pos + Vector (i*Global::STEP*Global::XSCALE, -dataY.at(i) ));
        }

    }



//-----------------------------------------------------------------------------
void drawStats (std::vector<FnStats> stats, std::vector<AL::Sprite> sprites)
    {
    assert (stats.size() <= sprites.size());

    for (int i = 0; i < stats.size(); i++)
        {
        drawGraph (Vector (0, Global::WinSize.y),                   stats.at(i).comps_, sprites.at(i));
        drawGraph (Vector (Global::WinSize.x/2, Global::WinSize.y), stats.at(i).swaps_, sprites.at(i));
        }

    AL::Global::RenderWindow->display();
    }



//-----------------------------------------------------------------------------
void mProc ()
    {
    //std::vector<FnStats> stats = mltFullFnStats ({   FnStats {"SelectSort", SelectSort},
                                                    // FnStats {"BubbleSort", BubbleSort}   });
    //drawStats (stats, Global::Res->sprites_);

    while (WindowIsOpen())
        {

        if (!GetAsyncKeyState (VK_SPACE)) continue;

        std::vector<FnStats> stats = mltFullFnStats ({   FnStats {"SelectSort", SelectSort},
                                                         FnStats {"BubbleSort", BubbleSort}   });
        drawStats (stats, Global::Res->sprites_);

        AL::Global::RenderWindow->clear();
        }
    }


//-----------------------------------------------------------------------------
int main ()
    {
    sf::RenderWindow win (sf::VideoMode (Global::WinSize.x, Global::WinSize.y), "okno");
    AL::Global::RenderWindow = &win;

    Resources res ({ "ball_3.png", "ball_1.png"});
    Global::Res = &res;


    mProc ();
    }


//}
//-----------------------------------------------------------------------------

 //   int ar[10][15]
  //  f (int ar [][15])
 //    {
  //    ar[y][x]
   //   (int*) ( ((char*) ar) + (y*15 + x) * sizeof(int) )
  //   }

//////////////////////////////////////////////////
//bit arithmetics
// signed char (char)
//     min = -128 max = 127 (0 1111111)
//
//
//     127 -> -128
//
//     I) 127 (0 1111111) + 1 (1)  = 1 0000000  (> char) unsigned(temporary)
//    II) 128 (1 0000000)  invert        (0 -> 1 && 1->0      +1)  0 1111111     1 0000000 (-128)
//
//
//
//
//
//     0 101 - 0 101
//     0 101 + 1 011 = 10000 = 0 000
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//


