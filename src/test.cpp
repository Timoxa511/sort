
#include "TXLib.h"
#define coolTXcolors

#include "int_t.h"



//-----------------------------------------------------------------------------
template <typename T>
int Search (T arr [], size_t arrsz, T lostCat)
    {
    for (int i = 0; i < arrsz; i++)
        {
        if (lostCat <= arr[i]) return i;
        }

    return arrsz;
    }


//-----------------------------------------------------------------------------
template <typename T>
void Shift (T arr [], size_t arrsz)
    {
    assert (arr);
    assert (arrsz);

    if (arrsz <= 1) return;
    if (arrsz == 2) {Swap (arr[0], arr[1]); return;}


    int buf = arr[arrsz - 1];
    for (int i = arrsz - 1; i > 0; i--)
        {
        arr[i] = arr[i - 1];
        }
    arr[0] = buf;
    }


//-----------------------------------------------------------------------------
template <typename T>
int BinSearch (T arr [], size_t arrsz, T lostCat)
    {
    int lEdge = 0;
    int rEdge = arrsz - 1;

    int mid = (rEdge + lEdge)/2;

    while (lEdge < rEdge)
        {
        //Printf (arr, arrsz, lEdge, mid, rEdge, true, "still searching");

        if (arr[mid] == lostCat) return mid;
        if (arr[mid] <  lostCat) lEdge = mid + 1;
                            else rEdge = mid;

        mid = (rEdge + lEdge)/2;
        }

    return lEdge;
    }



//-----------------------------------------------------------------------------
template <typename T>
void InsertionSort (T arr [], size_t arrsz)
    {
    assert (arr);
    assert (arrsz);

    if (arrsz <= 1) return;

    if (arr[0] > arr[1]) Swap (arr[0], arr[1]);
    if (arrsz == 2) return;

    //Printf (arr, arrsz, 1, 2, 3, true, "optimization");

    for (int i = 2; i < arrsz; i++)
        {
        //printf ("\ni = %d", i);
        //printf ("\nSearch (arr, i<%d>, arr[i]<%d>)\n", i, arr[i]);

        int catsBox = BinSearch (arr, i, arr[i]);

        //printf ("\ncatsBox = %d", catsBox);
        //printf ("\nShift (&arr[catsBox<%d>], i - catsBox + 1 <%d>\n", catsBox, i - catsBox + 1);


        Shift (&arr[catsBox], i - catsBox + 1);

        //Printf (arr, arrsz, -1, catsBox, i + 1, true, "after Shift");
        }


    }




//-----------------------------------------------------------------------------
int main ()
    {
    int ar [10] = {};
    FillArr (ar);

    Printf (ar, 1, 2, 3, true, "filling");

    //printf ("\n %d ", BinSearch (ar, sizearr (ar), 10));
    InsertionSort (ar, sizearr(ar));

    Printf (ar, 1, 2, 3, true, "sorting");


    }





