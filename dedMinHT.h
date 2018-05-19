#include "TXLib.h"

struct int_t
    {
    int val;

    static int comps_, swaps_;
    static void resetCounters();
    operator int () const;
    };

int int_t::comps_ = 0;
int int_t::swaps_ = 0;

int_t operator "" t (unsigned long long val);
int_t operator "" t (unsigned long long val)
    {
    return int_t { (int) val };
    }

int operator > (const int_t& a, const int_t& b);
int operator > (const int_t& a, const int_t& b)
    {
    int_t::comps_++;
    return a.val > b.val;
    }

void int_t::resetCounters ()
    {
    comps_ = 0;
    swaps_ = 0;
    }

int_t::operator int () const
    {
    return val;
    }

void Swap (int_t& a, int_t& b);
void Swap (int_t& a, int_t& b)
    {
    int_t::swaps_++;
    int_t tmp = a; a = b; b = tmp;
    }

std::ostream& operator << (std::ostream& stream, const int_t& value);
std::ostream& operator << (std::ostream& stream, const int_t& value)
    {
    stream << value.val;
    return stream;
    }

template <typename T>
void Sort (T arr[], int size)
    {
    for (int n = 0; n < size; n++)
    for (int i = 0; i < size-1-n; i++)
        if (arr[i] > arr[i+1])
            Swap (arr[i], arr[i+1]);
    }

template <typename T, int Size>
void Sort (T (&arr) [Size])
    {
    Sort (arr, Size);
    }

/*int main()
    {
    int_t arr[] = { 10_t, 9_t, 7_t, 14_t, 2_t };

    $(arr);

    Sort (arr);

    $(arr);

    $(int_t::comps_);
    $(int_t::swaps_);
    }  */
