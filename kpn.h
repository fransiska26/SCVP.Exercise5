#ifndef KPN_H
#define KPN_H

#include <systemc.h>

template <class T>
SC_MODULE(kpn)
{
private:
    sc_fifo<T> a,b,c,d;
    sc_signal<T> e;
    void add();     
    void delay();   
    void split(); 


public:
    SC_CTOR(kpn): a(10), b(10), c(10), d(10), e(0)
    {   
        b.write(1);
        c.write(0);

        SC_THREAD(add);
        SC_THREAD(delay);
        SC_THREAD(split);        
    }
};

#endif // KPN_H
