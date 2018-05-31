//sorts_pack
#include "TXLib.h"         //math.h,
#include "homemade_int.h"
#include "templates.h"     //homemade_int.h

#include <windows.h>
#include <stdio.h>


#define id(n) n     //TODO

//#define PrintfDebug



//{Protoypes-------------------------------------------------------------------
bool BubbleSortTest ();
//}
//-----------------------------------------------------------------------------


//=============================================================================


//{Template_fns----------------------------------------------------------------
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

//{Functions-------------------------------------------------------------------
using sort_fn_t = void (int_t arr [], size_t arrsz);
void multyfuncStatistic (std::initializer_list <sort_fn_t*> list)
    {
    for (auto& sort_fn : list)
        {
        int freq = 100;
        int_t experimentalMouse [freq] = {};

        for (int i = 10; i <= freq; i += 10)
            {
            FillArr (experimentalMouse, i);

            int_t::resetCounters ();
            sort_fn (experimentalMouse, i);
            printf ("[comps %d | swaps %d]    ", int_t::comps_, int_t::swaps_);
            }
        printf ("\n\nnext\n\n");
        }
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
int main ()
    {
    #ifdef PrintfDebug
    Test ();
    #else

    multyfuncStatistic ({BubbleSort, SelectSort});

    #endif
    }



//-----------------------------------------------------------------------------

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


