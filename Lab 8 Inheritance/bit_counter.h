//
// Created by gwdin on 4/29/2022.
//

#ifndef INHERITANCE_BIT_COUNTER_H
#define INHERITANCE_BIT_COUNTER_H

#include "counter.h"
#include <string>

using namespace std;

class bit_counter : public int_counter{
public:
    explicit bit_counter(unsigned int s) {
        _size = s;
        _binary = string(_size, '0');
    }
    void increment() override {
        if(_binary.back() == '0'){
            _binary.back() = '1';
            return;
        }
        if(_binary.back() == '1'){
            _binary.back() = '0';
            for(int i= _size - 2; i >= 0; --i){
                if(_binary.at(i) == '0'){
                    _binary.at(i) = '1';
                    break;
                }
                if(_binary.at(i) == '1'){
                    _binary.at(i) = '0';
                }
            }
        }
    }

    string to_string() override { return _binary; }

    void reset() override{
        _binary = string(_size, '0');
    }


private:
    int _size;
    string _binary;
};

#endif //INHERITANCE_BIT_COUNTER_H
