
// g++ -c int_t.cpp & g++ -shared -o int_t.dll -Wl,--out-implib,libint_t.a int_t.o

#define DLLFUNC __declspec(dllexport)

#include "int_t.h"

unsigned int int_t::assignments_ = 0;
unsigned int int_t::comparisons_ = 0;


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
    {
    assignments_ += 1;
    }

//-----------------------------------------------------------------------------
int_t::int_t (const int_t& int_o) :
    val_ (int_o.val_)
    {
    assignments_ += 1;
    }


//=============================================================================
void int_t::resetCounters ()
    {
    assignments_ = 0;
    comparisons_ = 0;
    }


//-----------------------------------------------------------------------------
unsigned int* int_t::getAssignments ()
    {
    return &assignments_;
    }

//-----------------------------------------------------------------------------
unsigned int* int_t::getComparisons ()
    {
    return &comparisons_;
    }


//-----------------------------------------------------------------------------
int int_t::getVal () const
    {
    return val_;
    }


//-----------------------------------------------------------------------------
void int_t::operator = (const int_t& int_o)
    {
    val_ = int_o.val_;
    assignments_ += 1;
    static int _4to_nibud = 0;
    if (!_4to_nibud++) printf ("int_t::assignments_ 0x%p\n", &assignments_);
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
    int_t::comparisons_ += 1;
    return a.getVal() < b.getVal();
    }

bool operator <= (const int_t& a, const int_t& b)
    {
    int_t::comparisons_ += 1;
    return a.getVal() <= b.getVal();
    }

bool operator > (const int_t& a, const int_t& b)
    {
    int_t::comparisons_ += 1;
    return a.getVal() > b.getVal();
    }

bool operator >= (const int_t& a, const int_t& b)
    {
    int_t::comparisons_ += 1;
    return a.getVal() >= b.getVal();
    }

bool operator == (const int_t& a, const  int_t& b)
    {
    int_t::comparisons_ += 1;
    return a.getVal() == b.getVal();
    }


void Swap (int_t& a, int_t& b)
    {
    if (&a == &b) return;
    std::swap (a, b);
    }

int_t operator "" _t (unsigned long long a)
    {
    return int_t((int) a);
    }

//}
//-----------------------------------------------------------------------------
