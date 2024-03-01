#include <unistd.h>
#include <systemc.h>

#include "kpn.h"

template<>
void kpn<unsigned int>::add(){
    // The process Add reads one integer number from each of its input a and c and writes the sum of both numbers to its output b (b = a + c).
    while(true){
        b.write(a.read() + c.read()); 
    }
};

template<>
void kpn<unsigned int>::split(){
    // The Split process copies its input b to two FIFOs (a and d) and to the output signal e
    unsigned int val; 
    for (unsigned int i=0; i<10; i++){
        val = b.read();
        e.write(val);
        a.write(val);
        d.write(val);
        cout << "The output is " << e.read() << endl;
    };
    sc_stop();
};


template<>
void kpn<unsigned int>::delay(){
    // The process Delay writes its input d to its output c. Two FIFOs are initialized with single values: b = 1 and c = 0.    while(true){
        for (unsigned int i=0; i<10; i++){
            c.write(d.read());
    };
};