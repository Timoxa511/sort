#include <stdio.h>
#include <assert.h>
#include <algorithm>


#define UnitTest(f)    bool f##Test ()
#define sizearr(arr)   sizeof(arr)/sizeof(arr[0])
#define sqr(x)  ((x)*(x))
#define id(n) n
#define arrSize(n) doNotUsearrSizeWithPointers(n)
//typedef unsigned int size_t;

void BubbleSort (int arr [], size_t arrsz);
//-----------------------------------------------------------------------------
template <typename T, int N>
constexpr int arrSize (T (&arr) [N])      //constexpr means that instead of function call expression will be placed (Yoda)    c++11
    {
    return N;
    }

//-----------------------------------------------------------------------------

int main  ()
    {
    int arr [] = {3, 6, 9, 23, 5};
    BubbleSort (arr, arrSize(arr));

    BubbleSortTest ();


    }



//-----------------------------------------------------------------------------
void BubbleSort (int arr [], size_t arrsz)
    {
    printf ("%I64u  ", arrSize (arr));

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





