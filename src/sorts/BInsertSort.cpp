//DLL

#include "../int_t.h"

//static linkage int_t.dll

#include "../ISort.h"


extern "C" ISort* Create ();

//-----------------------------------------------------------------------------
template <typename T>
void Shift (T arr [], size_t arrsz)
    {
    assert (arr);
    assert (arrsz);

    if (arrsz <= 1) return;
    if (arrsz == 2) {Swap (arr[0], arr[1]); return;}


    T buf = arr[arrsz - 1];
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
void Sort (T arr [], size_t arrsz)
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


        Shift (arr + catsBox, i - catsBox + 1);

        //Printf (arr, arrsz, -1, catsBox, i + 1, true, "after Shift");
        }


    }



//{BInsertSort::---------------------------------------------------------------
class BInsertSort : public ISort
    {
    virtual void sort (int_t arr [], size_t arrsz) override;
    virtual const char*  getName ()                override;
    };

//-----------------------------------------------------------------------------
void BInsertSort::sort (int_t arr [], size_t arrsz)
    {
    Sort<int_t> (arr, arrsz);
    }

//-----------------------------------------------------------------------------
const char* BInsertSort::getName ()
    {
    return "BInsertSort";
    }


//}
//-----------------------------------------------------------------------------


__declspec(dllexport)
ISort* Create ()
    {
    return new BInsertSort;
    }






