//DLL

#include "int_t_templates.h"  // merge 'em into dll  and link   with com
#include "homemade_int.h"

//int_t.dll

#include "ISort.h"


extern "C" ISort* Create ();

//-----------------------------------------------------------------------------
template <typename T>
int MaxElemNumber (const T arr [], size_t arrsz)
    {
    int maxId = 0;
    for (int i = 1; i < arrsz; i++)
        {
        if (arr[ check(i) ] > arr[ check(maxId) ]) maxId = i;
        }
    return maxId;
    }


//-----------------------------------------------------------------------------
template <typename T>
void Sort (T arr [], size_t arrsz)
    {
    for (int i = arrsz - 1; i >= 0; i--)
        {
        //Printf (arr, arrsz, -1, MaxElemNumber(arr, i + 1), i + 1, true, "check ");
        Swap (arr [ check(MaxElemNumber(arr, i + 1)) ], arr[ check(i) ]);
        }
    }



//{SelectSort::----------------------------------------------------------------
class SelectSort : public ISort
    {
    virtual void sort (int_t arr [], size_t arrsz) override;
    virtual const char*  getName ()                override;
    virtual unsigned int getStats ()               override;
    virtual void       resetStats ()               override;
    };

//-----------------------------------------------------------------------------
void SelectSort::sort (int_t arr [], size_t arrsz)
    {
    Sort<int_t> (arr, arrsz);
    }

//-----------------------------------------------------------------------------
const char* SelectSort::getName ()
    {
    return "SelectSort";
    }


//-----------------------------------------------------------------------------
unsigned int SelectSort::getStats ()
    {
    return ((int_t::swaps_ << sizeof(int)*8/2) | ~(~0 << sizeof(int)*8/2) & int_t::comps_);    //TODO .h with fanshuy defines
    }

//-----------------------------------------------------------------------------
void SelectSort::resetStats ()
    {
    int_t::resetCounters ();
    }

//}
//-----------------------------------------------------------------------------


__declspec(dllexport)
ISort* Create ()
    {
    return new SelectSort;
    }



