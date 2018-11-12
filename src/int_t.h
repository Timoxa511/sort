
//#ifndef HINT
//#define HINT

#include "W:\terrain-of-serviceable-gears\array_function_pack.h"


#ifndef DLLFUNC
#define DLLFUNC __declspec(dllimport)
#endif

//{Prototypes------------------------------------------------------------------

class int_t                                                                //                                            .--.
    {                                                             //                                                     `.  \.
    private:                                                //                                                             \  \.
    int val_;                                             //                                                                .  \.
    public:                                              //                                                                 :   .
                                                        //                                                                  |    .
    DLLFUNC static unsigned int assignments_;          //                                                                   |    :
    DLLFUNC static unsigned int comparisons_;          //                                                                   |    |
    //-----------------------------                    //                   ..._  ___                                       |    |
                                                       //                  `."".`''''""--..___                              |    |
    public:                                            //                  ,-\  \             ""-...__         _____________/    |
    DLLFUNC int_t ();                                  //                  / ` " '                    `""""""""                  .
    DLLFUNC int_t (int val);                           //                  \                                                      L
    DLLFUNC int_t (const int_t& int_o);                //                  (>                                                      \.
                                                       //                 /                                                         \.
    DLLFUNC int getVal   () const;                     //                 \_    ___..---.                                            L
                                                       //                   `--'         '.                                           \ .
    DLLFUNC void operator =   (const int_t& int_o);    //                                 .                                           \_
    DLLFUNC int* operator &   ();                      //                                _/`.                                           `.._
    DLLFUNC      operator int () const;                 //                            .'     -.                                             `.
                                                        //                           /     __.-Y     /''''''-...___,...--------.._            |
                                                         //                         /   _."    |    /                ' .      \   '---..._    |
    DLLFUNC static void       resetCounters    ();        //                       /   /      /    /                _,. '    ,/           |   |
    DLLFUNC static unsigned int* getAssignments ();          //                    \_,'     _.'   /              /''     _,-'            _|   |
    DLLFUNC static unsigned int* getComparisons ();              //                        '     /               `-----''               /     |
    };                                                                    //               `...-'     davPalm                           `...-'

DLLFUNC bool operator <  (const int_t& a, const int_t& b);
DLLFUNC bool operator <= (const int_t& a, const int_t& b);
DLLFUNC bool operator >  (const int_t& a, const int_t& b);
DLLFUNC bool operator >= (const int_t& a, const int_t& b);
DLLFUNC bool operator == (const int_t& a, const int_t& b);

DLLFUNC int_t operator - (const int_t& a, const int_t& b);
DLLFUNC int_t operator + (const int_t& a, const int_t& b);
DLLFUNC int_t operator * (const int_t& a, const int_t& b);
DLLFUNC int_t operator / (const int_t& a, const int_t& b);

DLLFUNC int_t operator "" _t (unsigned long long a);

DLLFUNC void Swap (int_t& a, int_t& b);
//}
//-----------------------------------------------------------------------------


//{template-int_t-instance-----------------------------------------------------

int ArrCmp (const int_t ti [], int tvoiDostizhseniya, const int_t sinMaminoyPodrugi [], int podvigiSinaMaminoyPodrugi)
    {
    int bufSwaps = int_t::assignments_;
    int bufComps = int_t::comparisons_;

    int ret_val = ArrCmp<int_t> (ti, tvoiDostizhseniya, sinMaminoyPodrugi, podvigiSinaMaminoyPodrugi);

    int_t::assignments_ = bufSwaps;
    int_t::comparisons_ = bufComps;

    return ret_val;
    }


//-----------------------------------------------------------------------------
int ArrCmp (const int_t c3p0 [], int c3p0sz, std::initializer_list <int_t> arr2d2)
    {
    int bufSwaps = int_t::assignments_;
    int bufComps = int_t::comparisons_;

    int ret_val = ArrCmp<int_t> (c3p0, c3p0sz, arr2d2);

    int_t::assignments_ = bufSwaps;
    int_t::comparisons_ = bufComps;

    return ret_val;
    }


//}
//-----------------------------------------------------------------------------


//#endif











