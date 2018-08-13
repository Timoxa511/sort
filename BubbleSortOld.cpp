//sort BubbleSort dll

#include "homemade_int.h"
#include "int_t_templates.h"


//-----------------------------------------------------------------------------
template <typename T>    //template for sync with int_t for cmp counter
void Sort (T arr [], size_t arrsz)
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
__declspec(dllexport)
void Sort (int_t arr [], size_t arrsz)
    {
    Sort (arr, arrsz);
    }

