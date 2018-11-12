//sorts_pack

//g++ -c sortir.cpp & g++ sortir.o -o sortir.exe -lint_t -L.
#define coolTXcolors
#define _CRT_SECURE_NO_WARNINGS //for vs not to cry about it complexes


#ifdef coolTXcolors
#include "TXLib.h"  //only for colors
#endif

#include "Alib.h" // SFML/graphics.hpp .. + #include "AlibOperators.hpp"

#include "int_t.h" //static linkage int_t.dll

#include "ISort.h"  //dll interface class for interaction


#include <windows.h>
#include <stdio.h>


//{Protoypes-------------------------------------------------------------------

struct Stats
    {
    const char*      name_;

    std::vector<unsigned int> comps_;
    std::vector<unsigned int> swaps_;
    };


class Resources
    {
    public:
    std::vector <AL::Sprite>  sprites_;
    std::vector <sf::Texture> textures_;
    //---------------------

    Resources (std::initializer_list <const char*> fileNames);


    };


class CrdSys
    {
    public:
    Vector origPos_;
    Vector size_;
    //---------------------

    CrdSys (Vector origPos,
            Vector size);


    bool draw (AL::Sprite sprite);
    void draw (AL::Sprite bullet, std::vector<unsigned int> dataY);

    Vector localToAbstractCrd (Vector vector);
    bool spriteInArea (AL::Sprite& sprite);

    };



bool BubbleSortTest ();
Vector crdsysfiltre (Vector vector);

void Test ();
void Dump (const std::vector<Stats> &stats);

void drawLegend (std::vector<Stats> stats, std::vector<AL::Sprite> sprites);
void drawStats  (std::vector<Stats> stats, std::vector<AL::Sprite> sprites);
void drawFon    (AL::Sprite fon);


std::vector <Stats> mltFullStats (std::vector <ISort*> sorts);
Stats fullStats (ISort* sort);


std::vector<ISort*> LoadDlls ();


bool WindowIsOpen();
void mProc ();

namespace Global
    {
    const unsigned SIZE = 100;
    const unsigned STEP = 2;
    const uVector WinSize (1815, 1090);
    const  Vector SCALE  (4, 1);

    Resources* Res = nullptr;

    FILE* Log = nullptr;
    }

//}
//-----------------------------------------------------------------------------


//=============================================================================


//{classes---------------------------------------------------------------------


//{Resources::-----------------------------------------------------------------

Resources::Resources (std::initializer_list <const char*> fileNames) :
    sprites_  (),
    textures_ (fileNames.size())
    {
    int i = 0;
    for (auto& fileName : fileNames)
        {
        textures_.at(i).loadFromFile (fileName);


        AL::Sprite sprite (std::string("res") + std::to_string(i));
        sprite.setTexture (&textures_.at(i));
        sprite.setRenderWindow (AL::Global::RenderWindow);
        if (i) sprite.setOrigin (Vector (sprite.getTexture()->getSize())/2);   //fuck this shit lets buy troyka!  //fon is zero kostil' hack hack fuck fuck

        sprites_.push_back (sprite);

        i++;
        }
    }

//}
//-----------------------------------------------------------------------------



//{CrdSys::--------------------------------------------------------------------

CrdSys::CrdSys (Vector origPos, //leftTopCornerPos
                Vector size) :
    origPos_ (origPos),
    size_    (size)
    {
    }

//=============================================================================

bool CrdSys::draw (AL::Sprite sprite)
    {
    if (!spriteInArea(sprite)) return false;

    Draw ( sprite, localToAbstractCrd(sprite.getPosition() + Vector (sprite.getTexture()->getSize())/2)       );

    return true;
    }


//-----------------------------------------------------------------------------
void CrdSys::draw (AL::Sprite sprite, std::vector<unsigned int> dataY)
    {
    assert (dataY.size() < UINT_MAX);

    for (unsigned i = 0; i < dataY.size(); i++)
        {
        fprintf (Global::Log, "CrdSys::draw dataY.at(i) = %u", dataY.at(i));

        sprite.setPosition (Vector ((float) (i*Global::STEP), (float) (dataY.at(i)/10))*Global::SCALE);
        if (!draw (sprite)) return;
        }

    }


//-----------------------------------------------------------------------------
bool CrdSys::spriteInArea (AL::Sprite& sprite)
    {
    assert (sprite.getOrigin() == Vector (sprite.getTexture()->getSize())/2 );

    Vector lt  = localToAbstractCrd(sprite.getPosition());

    return (origPos_ <= lt && lt <= origPos_ + size_);
    }


//-----------------------------------------------------------------------------
Vector CrdSys::localToAbstractCrd (Vector vector)
    {
    return Vector (vector.x, size_.y - vector.y) + origPos_;
    }


//}
//-----------------------------------------------------------------------------



//}
//-----------------------------------------------------------------------------



//{Functions-------------------------------------------------------------------
Stats fullStats (ISort* sort)
    {

    Stats stats {};
    stats.name_ = sort->getName();

    int_t experimentalMouse [Global::SIZE] = {};

    for (unsigned i = Global::STEP; i <= Global::SIZE; i += Global::STEP)
        {
        int_t::resetCounters ();

        FillArr       (experimentalMouse, i);
        sort->sort    (experimentalMouse, i);
                                                    //TODO     sort->getName();
        stats.comps_.push_back (*int_t::getComparisons());
        stats.swaps_.push_back (*int_t::getAssignments());
        }
    printf ("int_t::getAssignments 0x%p\n", int_t::getAssignments());
    return stats;
    }



//-----------------------------------------------------------------------------
std::vector <Stats> mltFullStats (std::vector <ISort*> sorts)
    {
    std::vector<Stats> stats;

    for (auto& sort : sorts)
        {
        stats.push_back (fullStats (sort));
        }
    return stats;
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
void Dump (const std::vector<Stats> &stats)
    {
    #pragma GCC diagnostic ignored "-Wnonnull-compare"
    #pragma GCC diagnostic ignored "-Waddress"
    if (&stats == nullptr) {printf("null_param"); return;}
    #pragma GCC diagnostic default "-Waddress"
    #pragma GCC diagnostic default "-Wnonnull-compare"

    for (unsigned i = 0; i < stats.size(); i++)
        {
        assert (stats.at(i).swaps_.size() == stats.at(i).comps_.size());
        for (unsigned j = 0; j < stats.at(i).swaps_.size(); j++)
            {
            fprintf (Global::Log, "%s : comps[%u], swaps[%u]\n", stats.at(i).name_, stats.at(i).comps_.at(j), stats.at(i).swaps_.at(j));
            }
        }
    }




//-----------------------------------------------------------------------------
void drawFon (AL::Sprite fon)
    {
    Draw (fon, Vector (0, 0));
    }


//-----------------------------------------------------------------------------
void drawStats (std::vector<Stats> stats, std::vector<AL::Sprite> sprites)
    {
    assert (stats.size() <= sprites.size() - 2);   //1st is fon //temporr decision

    drawFon (sprites.at(0));//1st is fon //temporr decision

    CrdSys sysComps (Vector (365,  290), Vector (435, 535));

    CrdSys sysSwaps (Vector (1015, 290), Vector (435, 535));

    for (unsigned i = 0; i < stats.size(); i++)
        {
        sysComps.draw (sprites.at(i + 2), stats.at(i).comps_);
        sysSwaps.draw (sprites.at(i + 2), stats.at(i).swaps_);//1st is fon //temporr decision
        }
    }


//-----------------------------------------------------------------------------
void drawLegend (std::vector<Stats> stats, std::vector<AL::Sprite> sprites)
    {
    assert (stats.size() <= sprites.size() - 2);

    Draw(sprites.at(1), Vector(400, 1000));
    for (unsigned i = 0; i < stats.size(); i++)
        {
        printf ("\n Name: %s", stats.at(i).name_);
        Draw (sprites.at(i + 2), Vector((float) (400 - 20*i), (float) 1000));
        }
    }




//-----------------------------------------------------------------------------
std::vector<ISort*> LoadDlls ()
    {
    std::vector<ISort*> sorts;


    _WIN32_FIND_DATAA currentFileInfo = {};

    char path [_MAX_DIR] = "";
    getcwd(path, sizeof(path) - 1);



    _chdir("../res_sorts");  //if there is no directory the default one will stay /in MinGW/



    HANDLE prevFile = FindFirstFileA ("*.sort", &currentFileInfo);

    bool nextFile = (prevFile != INVALID_HANDLE_VALUE);

    while (nextFile)
        {

        HMODULE dll = LoadLibrary (currentFileInfo.cFileName);
        assert (dll);
        auto create = reinterpret_cast <ISort*(*)()> (GetProcAddress (dll, "Create"));
        assert (create);

        sorts.push_back (create());

        nextFile = FindNextFileA (prevFile, &currentFileInfo);
        }

    _chdir(path);

    return sorts;
    }



//-----------------------------------------------------------------------------
void mProc ()
    {
    std::vector<Stats> stats = mltFullStats (LoadDlls());

    Dump (stats);

    drawStats  (stats, Global::Res->sprites_);
    drawLegend (stats, Global::Res->sprites_);

    AL::Global::RenderWindow->display();


    while (WindowIsOpen())
        {}
    }


//-----------------------------------------------------------------------------
int main ()
    {
    Global::Log = fopen ("Log.txt", "a");

    sf::RenderWindow win (sf::VideoMode (Global::WinSize.x, Global::WinSize.y), "okno");
    AL::Global::RenderWindow = &win;

    Resources res ({ "Y:/res/field.jpg",
                     "Y:/res/wagon.png",
                     "Y:/res/carrot_lady1.png",
                     "Y:/res/carrot_lady2.png",
                     "Y:/res/carrot_lady3.png",
                     "Y:/res/carrot_lady4.png",
                     "Y:/res/carrot_lady5.png" });


    Global::Res = &res;


    mProc ();
    return 0;
    }


//}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
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



