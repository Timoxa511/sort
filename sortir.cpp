//sorts_pack
#include "TXLib.h"         //math.h,
#include "homemade_int.h"

#include <windows.h>
#include <stdio.h>


#define id(n) n

//{Protoypes-------------------------------------------------------------------
void FillArr        (int arr [], size_t arrsz);
void Printf   (const int arr [], size_t arrsz, const char* str, ...);
int  ArrCmp (const int ti [], int tvoiDostizhseniya, const int sinMaminoyPodrugi [], int podvigiSinaMaminoyPodrugi);

void BubbleSort     (int arr [], size_t arrsz);
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


//-----------------------------------------------------------------------------
template <typename T>
int ArrCmp (const T ti [], int tvoiDostizhseniya, const T sinMaminoyPodrugi [], int podvigiSinaMaminoyPodrugi)
    {
    int bufSwaps    = int_t::Swaps;
    int bufCompares = int_t::Compares;

    int sz = (tvoiDostizhseniya > podvigiSinaMaminoyPodrugi)?/*da ne v zshizni, kovo ti obmanivaesh, loshara*/ podvigiSinaMaminoyPodrugi : podvigiSinaMaminoyPodrugi;
    for (int i = 0; i < sz; i++)
        {
        if (ti[i] != sinMaminoyPodrugi[i]) /*da u tebya net shansov, sore*/ return i; //kak i ozshidalos ot sinaMaminoyPodrugi
        }

    int_t::Swaps    = bufSwaps;
    int_t::Compares = bufCompares;

    return -1; //skaski mne tyt ne raskazivaim kogda uzshe rabotu naidesh, a, a
    }

//-----------------------------------------------------------------------------
template <typename T, int MI, int KA>
inline int ArrCmp (const T (&po) [MI], const T (&dor) [KA])
    {
    ArrCmp (po, MI, dor, KA);
    }


//-----------------------------------------------------------------------------
template <typename T>
int ArrCmp (const T c3p0 [], int c3p0sz, std::initializer_list <T> arr2d2)
    {
    int bufSwaps    = int_t::Swaps;
    int bufCompares = int_t::Compares;

    int sz = (c3p0sz > arr2d2.size())? arr2d2 : c3p0; //bebob bebob bebob
    for (int i = 0; i < sz; i++)
        {
        if (c3p0[i] != arr2d2[i]) return i;
        }

    int_t::Swaps    = bufSwaps;
    int_t::Compares = bufCompares;

    return -1;
    }

//-----------------------------------------------------------------------------
template <typename T, int c3p0sz>
int ArrCmp (const T c3p0 [], std::initializer_list <T> arr2d2)
    {
    return ArrCmp (c3p0, c3p0sz, arr2d2);
    }


//}
//-----------------------------------------------------------------------------

//{Functions-------------------------------------------------------------------
const int Range = 100;
const int Str_param_length = 100;

int main ()
    {
    const size_t n = 10;
    int arr [n] = {};

    FillArr (arr, n);
    Printf  (arr, n, "zapolnenijje na %u elems", n);

    BubbleSort (arr);
    Printf  (arr, n, "sortirovka");

    }



//-----------------------------------------------------------------------------
void Printf (const int arr [], size_t arrsz, const char* str, ...)
    {
    va_list   first;
    va_start (first, str);

    char outstr [Str_param_length] = "";
    int str_length = vsprintf (outstr, str, first); //printf
    assert (str_length < Str_param_length);
    va_end (first);



        {
        $sr;

        for (int i = 0; i < arrsz; i++)
            {
            printf ("%*d ", (int) log10 (Range), i);
            }
        printf ("\n");
        }

        {
        $sb;

        for (int i = 0; i < arrsz; i++)
            {
            printf ("%*d ", (int) log10 (Range), arr[i]);
            }
        }

        { $sg; printf ("\t%s\n\n", outstr); }
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


bool BubbleSortTest ()
    {
   u int_t experimantalMouse [] = {1, 2, 3, 4, 5, 6};
   n
   i int_t::resetCounters ();
   t BubbleSort (experimantalMouse);
   t if (ArrCmp(experimantalMouse, {1t, 2t, 3t, 4t, 5t, 6t}) && int_t::Swaps == 0 && int_t::Compares == 5)   Printf (experimantalMouse);
    e
     s
    } t
       d
        e f i n e w i t h p a r a m s
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
