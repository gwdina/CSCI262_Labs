//
// Created by gwdin on 4/29/2022.
//

#ifndef INHERITANCE_BOUNDED_COUNTER_H
#define INHERITANCE_BOUNDED_COUNTER_H

#include "int_counter.h"

class bounded_counter : public int_counter {
public:
    explicit bounded_counter(unsigned int m) { _modulus = m; }

    void increment() override {
        if (_value >= _modulus) _value = _modulus;
        else _value++;
    }

private:
    unsigned int _modulus;
};

#endif //INHERITANCE_BOUNDED_COUNTER_H
