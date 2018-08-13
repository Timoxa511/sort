


//-----------------------------------------------------------------------------
class ISort
    {
    public:
    virtual void sort (int_t arr [], size_t arrsz) = 0;
    virtual const char* getName () = 0;
    virtual ~ISort () {};

    virtual void       resetStats () = 0;
    virtual unsigned int getStats () = 0;
    };


/*void ISort::resetStats ()
    {
    int_t::resetCounters ();
    }
       */

//unsigned int ISort::getStats ()
    //{
    /*((int_t::swaps_ << sizeof(int)*8/2) | ~(~0 << sizeof(int)*8/2) & int_t::comps_)*/  //00001111   //comps
    //}                                                                                                 //01010101   //swaps
                                                                                                      //00000101  <-operator &

                                                                                                      //thirstNm00000000
                                                                                                      //????????secondNm    //how to merge without spoiling first


                                                                                                      //0000000011111111 >-+              making mask
                                                                                                      //????????secondNm >-+
                                                                                                      //00000000secondNm <-+- oper &

                                                                                                      //thirstNm00000000 >-+
                                                                                                      //00000000secondNm >-+
                                                                                                      //                   |
                                                                                                      //thirstNmsecondNm <-+ oper |

                                                                                                      //if secNm will overfill, thirst will not fuck up



