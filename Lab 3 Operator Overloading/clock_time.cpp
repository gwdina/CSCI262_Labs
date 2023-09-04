/*
 * clock_time.cpp
 *
 * Put the definitions for the clock_time class and
 * supporting functions/operator-overloads here
 *
 * Author: Gordon Dina
 */

#include "clock_time.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

int clock_time::get_hour(){
    return (_seconds/3600);
};

int clock_time::get_minute(){
    return (_seconds % 3600) / 60;
};

int clock_time::get_second(){
    return (_seconds % 60);
};

void clock_time::set_time(int h, int m, int s) {
    while (h > 23){
        h = h - 24;
    }
    if (h < 0){
        h = 24 + h;
    }
    if (m < 0){
        h -= 1;
        m = 60 + m;
    }
    if (s < 0){
        m -= 1;
        s = 60 + s;
    }
    s += h * 3600;
    s += m * 60;
    _seconds = s;
}

clock_time::clock_time() {
    _seconds = 0;

}

clock_time::clock_time(int h, int m, int s){
    set_time(h, m, s);

}

ostream & operator<<(ostream & out, clock_time c){
    return out << to_string(c);
}
string to_string(clock_time c){
    int hh= c.get_hour();
    int mm = c.get_minute();
    int ss = c.get_second();
    string time;
    time = time + to_string(hh) + ":";

    if (mm < 10){
        time = time + "0";
    }
    time = time + to_string(mm) + ":";

    if (ss < 10){
        time = time + "0";
    }
    time = time + to_string(ss);

    return time;
}

bool operator==(clock_time a, clock_time b){
    if ((a.get_hour() == b.get_hour()) && (a.get_minute() == b.get_minute()) && (a.get_second() == b.get_second())){
        return true;
    }
    else{
        return false;
    }
}
clock_time operator+(clock_time a, clock_time b){
    return clock_time(a.get_hour() + b.get_hour(), a.get_minute() + b.get_minute(), a.get_second() + b.get_second());

}

bool operator!=(clock_time a, clock_time b){
    if ((a.get_hour() == b.get_hour()) && (a.get_minute() == b.get_minute()) && (a.get_second() == b.get_second())){
        return false;
    }
    else{
        return true;
    }
}

