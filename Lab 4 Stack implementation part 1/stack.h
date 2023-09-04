/*
 * stack.h
 *
 * Put the class declaration of the stack class here.
 *
 * Author: Gordon Dina
 */

#ifndef _STACK_H
#define _STACK_H

#include <string>
#include <cstddef>

using namespace std;

// Implements a simple stack of string values using dynamic
// arrays.
// Note: no underflow detection is performed.  Performing pop() or top()
// on an empty stack results in undefined behavior (probably crashing your
// program).
class stack {
public:
    string top();
    void push(const string &s);
    void pop();
    size_t size();
    bool is_empty();

    stack();
    ~stack(); //destructor

private:
    int _size;
    int _cap;
    string *_data;
};

#endif
