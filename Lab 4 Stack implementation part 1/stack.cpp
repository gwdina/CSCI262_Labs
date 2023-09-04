/*
 * stack.cpp
 *
 * Put the method definitions for the stack class here.
 *
 * Author: Gordon Dina
 */

#include "stack.h"

string stack::top(){
    string top =_data[_size -1];
    return top;
}

void stack::push(const string &s){
    if(_size == _cap){
        _cap *= 2;
        string *other = new string [_cap];
        for(int i =0; i < _size; ++i){
            other[i] = _data[i];
        }
        delete [] _data;
        _data = other;

    }
    _data[_size] = s;
    _size +=1;
}

void stack::pop(){
    _size -= 1;
}

size_t stack::size() {
    return _size;
}

bool stack::is_empty() {
    if (_size > 0){
        return false;
    }

    return true;
}


stack::stack(){
    _data = new string[_size+1];
    _size = 0; //total elements
    _cap = 1; //how much we can store

}

stack::~stack(){//destructor
    delete [] _data;
}