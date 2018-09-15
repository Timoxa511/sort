//DLL

#include "../int_t.h"

//static linkage int_t.dll

#include "../ISort.h"


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


//}
//-----------------------------------------------------------------------------


__declspec(dllexport)
ISort* Create ()
    {
    return new SelectSort;
    }



