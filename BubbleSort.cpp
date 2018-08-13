//DLL

#include "int_t_templates.h"  // merge 'em into dll  and link   with com
#include "homemade_int.h"

//int_t.dll

#include "ISort.h"


extern "C" ISort* Create ();

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
    virtual unsigned int getStats ()               override;
    virtual void       resetStats ()               override;
    };

//-----------------------------------------------------------------------------
void BubbleSort::sort (int_t arr [], size_t arrsz)
    {
    Sort<int_t> (arr, arrsz);
    }

//-----------------------------------------------------------------------------
const char* BubbleSort::getName ()
    {
    return "BubbleSort";
    }


//-----------------------------------------------------------------------------
unsigned int BubbleSort::getStats ()
    {
    return ((int_t::swaps_ << sizeof(int)*8/2) | ~(~0 << sizeof(int)*8/2) & int_t::comps_);
    }

//-----------------------------------------------------------------------------
void BubbleSort::resetStats ()
    {
    int_t::resetCounters ();
    }

//}
//-----------------------------------------------------------------------------


__declspec(dllexport)
ISort* Create ()
    {
    return new BubbleSort;
    }



