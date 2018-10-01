//DLL

#include "../int_t.h"

//static linkage int_t.dll

#include "../ISort.h"


extern "C" __declspec(dllexport) ISort* Create ();

//-----------------------------------------------------------------------------
template <typename T>
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



//{BubbleSort::----------------------------------------------------------------
class BubbleSort : public ISort
    {
    virtual void sort (int_t arr [], size_t arrsz) override;
    virtual const char*  getName ()                override;
    };

//-----------------------------------------------------------------------------
void BubbleSort::sort (int_t arr [], size_t arrsz)
    {
    printf ("\nname : %s\n array sz = %d\nprogress bar", getName(), arrsz);
    Sort<int_t> (arr, arrsz);
    }

//-----------------------------------------------------------------------------
const char* BubbleSort::getName ()
    {
    return "BubbleSort";
    }


//}
//-----------------------------------------------------------------------------


__declspec(dllexport)
ISort* Create ()
    {
    return new BubbleSort;
    }






