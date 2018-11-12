//DLL
#include "W:\terrain-of-serviceable-gears\array_function_pack.h"
#include "../int_t.h"  //the same but instanced

//static linkage int_t.dll

#include "../ISort.h"


extern "C" ISort* Create ();

//-----------------------------------------------------------------------------------------------------------
template <typename T>
int Partition (T ar [], size_t arrsz)
	{
	assert (ar);
	assert (arrsz);

	if (arrsz == 1) return -1;

	if (arrsz == 2) {if (ar[0] > ar[1]) Swap (ar[0], ar [1]); return -1;}

	size_t left_i = 0;
	T      mid_v  = ar[arrsz/2];
	size_t right_i = arrsz - 1;


	while (left_i < right_i)
		{
		while (left_i < right_i)
			{
			if (ar[left_i] >= mid_v) break;
            left_i++;
			}

		while (left_i < right_i)
			{
			if (ar[right_i] <= mid_v) break;
			right_i--;
			}

		if (left_i == right_i) break;
        assert (left_i < right_i);

		Swap(ar[right_i], ar[left_i]);
		left_i++;
		if ((right_i - left_i) > 2) right_i--;

		}
    return right_i + !(ar[right_i] >= mid_v);
	}


//-----------------------------------------------------------------------------
template <typename T>
void Sort (T arr [], size_t arrsz)
    {
    int right_i = Partition (arr, arrsz);


    if (right_i > 0) Sort (arr, right_i);


	if (right_i < arrsz) Sort (arr + right_i, arrsz - right_i);
    }



//{QuickSort::---------------------------------------------------------------
class QuickSort : public ISort
    {
    virtual void sort (int_t arr [], size_t arrsz) override;
    virtual const char*  getName ()                override;
    };

//-----------------------------------------------------------------------------
void QuickSort::sort (int_t arr [], size_t arrsz)
    {
    Sort<int_t> (arr, arrsz);
    }

//-----------------------------------------------------------------------------
const char* QuickSort::getName ()
    {
    return "QuickSort";
    }


//}
//-----------------------------------------------------------------------------


__declspec(dllexport)
ISort* Create ()
    {
    return new QuickSort;
    }







