/*
 * functions.cpp
 *
 * Author: Gordon Dina
 *
 * CSCI 262, Lab 2: Dynamic arrays
 * Various functions demonstrating working with dynamic arrays.
 *
 * Last modified: 1/26/2022
 */
#include "functions.h"
#include <cmath>
// return length of C string (not including nul-terminator)
// s will be a valid, nul-terminated C string (never nullptr)
size_t c_string_length(const char *s)
{
    int i = 0;
    int total = 0;
    while (s[i] != '\0')
    {
        ++total;
        ++i;
    }
    return total;
}
// return a dynamically allocated copy of a C string; if the
// input s is nullptr, nullptr should be returned
char *c_string_duplicate(const char *s)
{
    if (s == nullptr)
    {
        return nullptr;
    }
    int i = 0;
    int size = c_string_length(s);
    char *dup = new char[size + 1]; //'\0' not inclued so must add 1
    while (s[i] != '\0')
    {
        dup[i] = s[i];
        ++i;
    }
    dup[size] = '\0';
    return dup;
}
// return a dynamically allocated C string that is the concatenation
// of s and t; if either input is nullptr, nullptr should be returned
char *c_string_concat(const char *s, const char *t)
{
    if ((s == nullptr) || (t == nullptr))
    {
        return nullptr;
    }
    int i = 0;
    int n = 0;
    int size = c_string_length(s);
    int other = c_string_length(t);
    int totals = size + other;
    char *word = new char[totals + 1];
    while (s[i] != '\0')
    {
        word[i] = s[i];
        ++i;
    }
    while (t[n] != '\0')
    {
        word[i + n] = t[n];
        ++n;
    }
    word[totals] = '\0';
    return word;
}
// return a dynamically allocated array of doubles of size len
// containing the square roots of the values in arr; len will be > 0
double *square_roots_of_int_array(const int *arr, size_t len)
{
    double *root = new double[len];
    for (int i = 0; i < len; ++i)
    {
        root[i] = sqrt(arr[i]);
    }
    return root;
}
// deallocate the array pointer passed in
void deallocate_array(char *arr)
{
    delete[] arr;
}