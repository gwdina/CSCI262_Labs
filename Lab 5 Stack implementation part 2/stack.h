/*
 * stack.h
 *
 * Put the class and method template definitions in this file.
 * You should not create a .cpp file for this lab!
 *
 * Author: Your Name
 */

#ifndef _STACK_H
#define _STACK_H

#include <cstddef>

using namespace std;

// Implements a simple stack template class using dynamic arrays.
// Note: no underflow detection is performed.  Performing pop() or top()
// on an empty stack results in undefined behavior (probably crashing your
// program).
template <class T>
class stack {
public:
    stack();
    stack(const stack<T> &s); //copy
    T top();
    void push(const T &s);
    void pop();
    size_t size();
    bool is_empty();
   stack<T>& operator=(const stack<T> &s);


    ~stack(); //destructor

private:
    int _size;
    int _cap;
    T *_data;

};

template <class T> stack <T>& stack <T>::operator=(const stack<T> &s){
    if(this == &s){
       return *this;
    }
    _size = s._size;
    _cap = s._cap;
    delete[] _data;
    _data = new T[_cap];
    for (int j = 0; j < _size; j++) {
        _data[j] = s._data[j];
    }
    return *this;
}

template <class T> stack <T>::stack(const stack<T> &s){
    _size = s._size;
    _cap = s._cap;
    _data = new T[_cap];
    for(int j=0; j < _size; ++j){
        _data[j] = s._data[j];
    }

}


template <class T> T stack <T>::top(){
    T top =_data[_size -1];
    return top;
}

template <class T>void stack <T>::push(const T &s){
    if(_size == _cap){
        _cap *= 2;
        T *other = new T [_cap];
        for(int i =0; i < _size; ++i){
            other[i] = _data[i];
        }
        delete [] _data;
        _data = other;

    }
    _data[_size] = s;
    _size +=1;
}

template <class T> void stack <T>::pop(){
    _size -= 1;
}

template <class T> size_t stack <T>::size() {
    return _size;
}

template <class T> bool stack <T>::is_empty() {
    if (_size > 0){
        return false;
    }

    return true;
}


template <class T> stack <T>::stack(){
    _data = new T[_size+1];
    _size = 0; //total elements
    _cap = 1; //how much we can store

}

template <class T> stack <T>::~stack(){//destructor
    delete [] _data;
}

// Every method you implement outside of the class body requires
// a redeclaration of the template:

// To help you get started with the "big 3", this is what
// the copy constructor definition looks like (uncomment
// when ready for that part):
/*
template <class T>
stack<T>::stack(const stack<T>& s) {

}
*/

#endif
