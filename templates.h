//int & int_t template fns
#include "homemade_int.h"


//{Templates-------------------------------------------------------------------
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
const int Str_param_length = 300;

template <typename T, int c3p0sz>
int ArrCmp (const T c3p0 [], std::initializer_list <T> arr2d2)
    {
    return ArrCmp (c3p0, c3p0sz, arr2d2);
    }



//-----------------------------------------------------------------------------
const int Range = 100;

template <typename T>
void VPrintf (const T arr [], size_t arrsz, const char* str, va_list strPrms)
    {

    char outstr [Str_param_length] = "";
    int str_length = vsprintf (outstr, str, strPrms); //printf
    assert (str_length < Str_param_length);




        {


        for (int i = 0; i < arrsz; i++)
            {
            printf ("%*d ", (int) log10 (Range), i);
            }
        printf ("\n");
        }

        {


        for (int i = 0; i < arrsz; i++)
            {
            printf ("%*d ", (int) log10 (Range), (int) arr[i]);
            }
        }

        { $sy; printf ("\t%s\n\n", outstr); }
    }


//-----------------------------------------------------------------------------
template <typename T, int N>
void Printf (const T (&arr) [N], const char* str, ...)
    {
    va_list strPrms;
    va_start (strPrms, str);

    VPrintf (arr, N, str, strPrms);

    va_end (strPrms);
    }

//-----------------------------------------------------------------------------
template <typename T>
void Printf (const T arr [], size_t arrsz, const char* str, ...)
    {
    va_list strPrms;
    va_start (strPrms, str);

    VPrintf (arr, arrsz, str, strPrms);

    va_end (strPrms);
    }

//}
//-----------------------------------------------------------------------------


