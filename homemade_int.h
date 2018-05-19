
#ifndef HINT
#define HINT

#define _USE_MATH_DEFINES

#pragma GCC diagnostic ignored "-Weffc++"

//#include <sfml/graphics.hpp>
#include <windows.h>
#include <math.h>
#include <assert.h>
#include <string>

//{Prototypes------------------------------------------------------------------

class int_t
    {
    private:
    int val_;
    public:

    static int swaps_;
    static int comps_;
    //-----------------------------

    public:
    int_t ();
    int_t (int val);
    int_t (const int_t& int_o);


    static void resetCounters ();


    void operator =   (const int_t& int_o);
    int* operator &   ();
         operator int () const;

    int getval () const;
    };

int int_t::swaps_ = 0;
int int_t::comps_ = 0;

bool operator <  (const int_t& a, const int_t& b);
bool operator <= (const int_t& a, const int_t& b);
bool operator >  (const int_t& a, const int_t& b);
bool operator >= (const int_t& a, const int_t& b);
bool operator == (const int_t& a, const int_t& b);
void Swap (int_t& a, int_t& b);
//}
//-----------------------------------------------------------------------------


//=============================================================================


//{int_t::---------------------------------------------------------------------
int_t::int_t () :
    val_ (rand())
    {
    //initialize vars, dont use def constructors }:&

    }

//-----------------------------------------------------------------------------
int_t::int_t (int val) :
    val_ (val)
    {}

//-----------------------------------------------------------------------------
int_t::int_t (const int_t& int_o) :
    val_ (int_o.val_)
    {}


//=============================================================================
void int_t::resetCounters ()
    {
    swaps_ = 0;
    comps_ = 0;
    }


//-----------------------------------------------------------------------------
int int_t::getval () const
    {
    return val_;
    }



void int_t::operator = (const int_t& int_o)
    {
    val_ = int_o.val_;
    }

//-----------------------------------------------------------------------------
int_t::operator int () const
    {
    return val_;
    }

//-----------------------------------------------------------------------------
int* int_t::operator & ()
    {
    return &val_;
    }

//}
//-----------------------------------------------------------------------------


//{operators-------------------------------------------------------------------
int_t operator - (const int_t& a, const int_t& b)
    {
    return a.getval() - b.getval();
    }

int_t operator + (const int_t& a, const int_t& b)
    {
    return a.getval() + b.getval();
    }

int_t operator * (const int_t& a, const int_t& b)
    {
    return a.getval() * b.getval();
    }

int_t operator / (const int_t& a, const int_t& b)
    {
    return a.getval() / b.getval();
    }

bool operator < (const int_t& a, const int_t& b)
    {
    int_t::comps_ += 1;
    return a.getval() < b.getval();
    }

bool operator <= (const int_t& a, const int_t& b)
    {
    int_t::comps_ += 1;
    return a.getval() <= b.getval();
    }

bool operator > (const int_t& a, const int_t& b)
    {
    int_t::comps_ += 1;
    return a.getval() > b.getval();
    }

bool operator >= (const int_t& a, const int_t& b)
    {
    int_t::comps_ += 1;
    return a.getval() >= b.getval();
    }

bool operator == (const int_t& a, const  int_t& b)
    {
    int_t::comps_ += 1;
    return a.getval() == b.getval();
    }


void Swap (int_t& a, int_t& b)
    {
    int_t::swaps_ += 1;
    std::swap (a, b);
    }

void TempSwap (int_t arr [], int a, int b)
    {
    int_t::swaps_ += 1;
    std::swap (arr[a], arr[b]);
    }

int_t operator "" t (unsigned long long a)
    {
    return int_t(a);
    }

//}
//-----------------------------------------------------------------------------



#endif







