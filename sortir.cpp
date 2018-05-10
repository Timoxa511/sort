//sorts_pack
#include "TXLib.h"         //math.h,
#include "homemade_int.h"
#include "templates.h"     //homemade_int.h

#include <windows.h>
#include <stdio.h>


#define id(n) n     //TODO

//#define PrintfDebug

//{Protoypes-------------------------------------------------------------------
void FillArr         (int arr [], size_t arrsz);

int  ArrCmp (const int ti [], int tvoiDostizhseniya, const int sinMaminoyPodrugi [], int podvigiSinaMaminoyPodrugi);

bool BubbleSortTest ();
//}
//-----------------------------------------------------------------------------


//=============================================================================


//{Templates-------------------------------------------------------------------
template <typename T>    //template for sync with int_t for cmp counter
void BubbleSort (T arr [], size_t arrsz)
    {
    for (int i = 0; i < arrsz; i++)
        {
        int sorted = true;
        for (int j = 0; j < arrsz - 1 - i; j++)
            {
            assert (0 <= j && j < arrsz);
            assert (0 <= j + 1 && j + 1 < arrsz);

            if (arr[id(j)] > arr[id(j + 1)])  { std::swap (arr[j], arr[j + 1]); sorted = false; }
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


//}
//-----------------------------------------------------------------------------

//{Functions-------------------------------------------------------------------
void Test ()
    {
    const size_t n = 10;
    int arr [n] = {};

    FillArr (arr, n);
    Printf  (arr, n, "zapolnenijje na %u elems", n);

    BubbleSort (arr);
    Printf  (arr, "sortirovka");

    }


//-----------------------------------------------------------------------------
int main ()
    {
    #ifdef PrintfDebug
    Test ();
    #else
    BubbleSortTest ();
    #endif
    }



//-----------------------------------------------------------------------------
void FillArr (int arr [], size_t arrsz)
    {

    for (int i = 0; i < arrsz; i++)
        {
        arr[i] = rand() % Range;
        }

    }


//-----------------------------------------------------------------------------

#define unitTest(initializer_list, expected, swaps, compares)                                                                                         \
    {                                                                                                                                                 \
    int_t experimantalMouse [] = initializer_list;                                                                                                    \
    int_t::resetCounters ();                                                                                                                          \
    BubbleSort (experimantalMouse);                                                                                                                   \
    if (ArrCmp(experimantalMouse, expected) && int_t::Swaps == swaps && int_t::Compares == compares)  {$sg; Printf (experimantalMouse, "uTest");}     \
                                                                                                 else {$sr; Printf (experimantalMouse, "uTest");}     \
    }

#define _ ,

bool BubbleSortTest ()
    {
    unitTest ({1t}, {1t}, 0, 0);
    unitTest ({1t _ 2t _ 3t _ 4t _ 5t _ 6t}, {1t _ 2t _ 3t _ 4t _ 5t _ 6t}, 0, 5);

    //unitTest ({1t _ 4t _ 3t _ 2t _ 5t _ 6t}, {1t _ 2t _ 3t _ 4t _ 5t _ 6t}, 0, 5);
    }

#undef unitTest
//-----------------------------------------------------------------------------
/*void SelectSort (int arr [], size_t arrsz)
    {


    }


     */



//}
//-----------------------------------------------------------------------------

 //   int ar[10][15]
  //  f (int ar [][15])
 //    {
  //    ar[y][x]
   //   (int*) ( ((char*) ar) + (y*15 + x) * sizeof(int) )
    // }
