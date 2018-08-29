
// g++ -c int_t.cpp & g++ -shared -o int_t.dll -Wl,--out-implib,libint_t.a int_t.o

#include "int_t.h"


int int_t::swaps_ = 0;
int int_t::comps_ = 0;


//Definition

//{class--int_t::--------------------------------------------------------------
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
unsigned int int_t::getSwaps ()
    {
    return swaps_;
    }

//-----------------------------------------------------------------------------
unsigned int int_t::getComps ()
    {
    return comps_;
    }


//-----------------------------------------------------------------------------
int int_t::getVal () const
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


//{non_class_operators---------------------------------------------------------
int_t operator - (const int_t& a, const int_t& b)
    {
    return a.getVal() - b.getVal();
    }

int_t operator + (const int_t& a, const int_t& b)
    {
    return a.getVal() + b.getVal();
    }

int_t operator * (const int_t& a, const int_t& b)
    {
    return a.getVal() * b.getVal();
    }

int_t operator / (const int_t& a, const int_t& b)
    {
    return a.getVal() / b.getVal();
    }

bool operator < (const int_t& a, const int_t& b)
    {
    int_t::comps_ += 1;
    return a.getVal() < b.getVal();
    }

bool operator <= (const int_t& a, const int_t& b)
    {
    int_t::comps_ += 1;
    return a.getVal() <= b.getVal();
    }

bool operator > (const int_t& a, const int_t& b)
    {
    int_t::comps_ += 1;
    return a.getVal() > b.getVal();
    }

bool operator >= (const int_t& a, const int_t& b)
    {
    int_t::comps_ += 1;
    return a.getVal() >= b.getVal();
    }

bool operator == (const int_t& a, const  int_t& b)
    {
    int_t::comps_ += 1;
    return a.getVal() == b.getVal();
    }


void Swap (int_t& a, int_t& b)
    {
    if (&a == &b) return;
    int_t::swaps_ += 1;
    std::swap (a, b);
    }

int_t operator "" _t (unsigned long long a)
    {
    return int_t((int) a);
    }

//}
//-----------------------------------------------------------------------------
