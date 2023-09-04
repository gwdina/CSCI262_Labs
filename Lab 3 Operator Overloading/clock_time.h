/*
 * clock_time.h
 *
 * Put the class declaration of the clock_time class
 * and supporting function/operator-overload
 * declarations here
 *
 * Author: Gordon Dina
 */

#ifndef _CLOCK_TIME_H
#define _CLOCK_TIME_H
#include <string>
#include <fstream>
using namespace std;

class clock_time {
public:
    friend bool operator==(clock_time a, clock_time b);
    friend clock_time operator+(clock_time a, clock_time b);
    friend bool operator!=(clock_time a, clock_time b);
    int get_hour();

    int get_minute();

    int get_second();

    void set_time(int h, int m, int s);

    clock_time();

    clock_time(int h, int m, int s);



private:
    int _seconds;
};

ostream & operator<<(ostream & out, clock_time c);
string to_string(clock_time c);


#endif
