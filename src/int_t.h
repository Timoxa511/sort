
//#ifndef HINT
//#define HINT

#define _USE_MATH_DEFINES 1

#pragma GCC diagnostic ignored "-Weffc++"

#include <windows.h>
#include <math.h>
#include <assert.h>
#include <string>



#ifndef coolTXcolors
#define $sd {;}
#define $m  {;}
#define $c  {;}    //-Wempty-body is a pretty cutie   <3
#define $y  {;}
#define $b  {;}
#endif


#define check(f_id)                                     \
({int id = f_id; assert (0 <= id && id < arrsz); id;})       //gcc spec

#ifndef DLLFUNC 
#define DLLFUNC __declspec(dllimport)
#endif

//{Prototypes------------------------------------------------------------------

class int_t
    {
    private:
    int val_;
    public:

    DLLFUNC static unsigned int assignments_;
    DLLFUNC static unsigned int comparisons_;
    //-----------------------------

    public:
    DLLFUNC int_t ();
    DLLFUNC int_t (int val);
    DLLFUNC int_t (const int_t& int_o);

    DLLFUNC int getVal   () const;

    DLLFUNC void operator =   (const int_t& int_o);
    DLLFUNC int* operator &   ();
    DLLFUNC      operator int () const;


    DLLFUNC static void       resetCounters    ();
    DLLFUNC static unsigned int* getAssignments ();
    DLLFUNC static unsigned int* getComparisons ();
    };

DLLFUNC bool operator <  (const int_t& a, const int_t& b);
DLLFUNC bool operator <= (const int_t& a, const int_t& b);
DLLFUNC bool operator >  (const int_t& a, const int_t& b);
DLLFUNC bool operator >= (const int_t& a, const int_t& b);
DLLFUNC bool operator == (const int_t& a, const int_t& b);

DLLFUNC int_t operator - (const int_t& a, const int_t& b);
DLLFUNC int_t operator + (const int_t& a, const int_t& b);
DLLFUNC int_t operator * (const int_t& a, const int_t& b);
DLLFUNC int_t operator / (const int_t& a, const int_t& b);

DLLFUNC int_t operator "" _t (unsigned long long a);

DLLFUNC void Swap (int_t& a, int_t& b);
//}
//-----------------------------------------------------------------------------


//{template_stuff--------------------------------------------------------------
template <typename T>
int ArrCmp (const T ti [], int tvoiDostizhseniya, const T sinMaminoyPodrugi [], int podvigiSinaMaminoyPodrugi)
    {
    int bufSwaps = int_t::assignments_;
    int bufComps = int_t::comparisons_;

    int sz = (tvoiDostizhseniya > podvigiSinaMaminoyPodrugi)?/*da ne v zshizni, kovo ti obmanivaesh, loshara*/ podvigiSinaMaminoyPodrugi : podvigiSinaMaminoyPodrugi;
    for (int i = 0; i < sz; i++)
        {
        if (ti[i] != sinMaminoyPodrugi[i]) /*da u tebya net shansov, sore*/ return i; //kak i ozshidalos ot sinaMaminoyPodrugi
        }

    int_t::assignments_ = bufSwaps;
    int_t::comparisons_ = bufComps;

    return -1; //skaski mne tyt ne raskazivaim kogda uzshe rabotu naidesh, a, a
    }


//-----------------------------------------------------------------------------
template <typename T, int MI, int KA>
inline int ArrCmp (const T (&po) [MI], const T (&dor) [KA])
    {
    return ArrCmp (po, MI, dor, KA);
    }



//-----------------------------------------------------------------------------
template <typename T>
int ArrCmp (const T c3p0 [], int c3p0sz, std::initializer_list <T> arr2d2)
    {
    int bufSwaps = int_t::assignments_;
    int bufComps = int_t::comparisons_;

    int sz = (c3p0sz < arr2d2.size())? c3p0sz : arr2d2.size() ; //bebob bebob bebob
    auto iter = arr2d2.begin();
    for (int i = 0; i < sz; i++)
        {
        if (c3p0[i] != *iter++) return i;
        }

    int_t::assignments_ = bufSwaps;
    int_t::comparisons_ = bufComps;

    return -1;
    }



//-----------------------------------------------------------------------------
template <typename T, int c3p0sz>
int ArrCmp (const T (&c3p0) [c3p0sz], std::initializer_list <T> arr2d2)
    {
    return ArrCmp (c3p0, c3p0sz, arr2d2);
    }



//-----------------------------------------------------------------------------

const int Str_param_length = 300;
const int Range = 100;

template <typename T>
void PrintfHeart (const T arr [], size_t arrsz, int lEdge, int curr, int rEdge, bool numeration, const char* str, va_list strPrms)
    {
    assert (lEdge <= curr && curr < rEdge);

        {
        $sd
        if (numeration)
        for (int i = 0; i < arrsz; i++)
            {
            printf ("%*d ", (int) log10 (Range), i);
            }


        printf ("\n");


        for (int i = 0; i < arrsz; i++)
            {
            if (i == curr) $m
            else if (i <= lEdge) $c
            else if (lEdge < i && i < rEdge) $y
            else if (rEdge <= i) $b

            printf ("%*d ", (int) log10 (Range), (int) arr[i]);
            }
        }


    char outstr [Str_param_length] = "";
    int str_length = vsprintf (outstr, str, strPrms); //printf
    assert (str_length < Str_param_length);

    CONSOLE_SCREEN_BUFFER_INFO bundleOfGears = {};
    GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), &bundleOfGears);
    int consoleLen = bundleOfGears.dwSize.X;
    int cursorPosX = bundleOfGears.dwCursorPosition.X;

    printf ("%*s\n", consoleLen - cursorPosX - 1, outstr);
    }

//-----------------------------------------------------------------------------
template <typename T, int N>
void Printf (const T (&arr) [N], int lEdge, int curr, int rEdge, bool numeration, const char* str, ...)
    {
    va_list strPrms;
    va_start (strPrms, str);

    PrintfHeart (arr, N,     lEdge, curr, rEdge, numeration, str, strPrms);

    va_end (strPrms);
    }

//-----------------------------------------------------------------------------
template <typename T>
void Printf (const T arr [], size_t arrsz, int lEdge, int curr, int rEdge, bool numeration, const char* str, ...)  //do not make blackcolor in rEdge or al will fuck up
    {
    va_list strPrms;
    va_start (strPrms, str);

    PrintfHeart (arr, arrsz, lEdge, curr, rEdge, numeration, str, strPrms);

    va_end (strPrms);
    }



//-----------------------------------------------------------------------------
template <typename T>
void FillArr (T arr [], size_t arrsz)
    {

    for (int i = 0; i < arrsz; i++)
        {
        arr[i] = rand() % Range;
        }
    }

//-----------------------------------------------------------------------------
template <typename T, int N>
void FillArr (T (&arr) [N])
    {
    FillArr (arr, N);
    }


//-----------------------------------------------------------------------------
template <typename T>
void Swap (T& a, T& b)
    {
    if (&a == &b) return;
    std::swap (a, b);
    }


//}
//-----------------------------------------------------------------------------


//#endif











