//
// Created by gwdin on 3/31/2022.
//

#include "Babylonian.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>

Babylonian::Babylonian(){
    _root;
    _guess;
    _number;
    _collector;
}

void Babylonian::getter(int num, int gus){
    _guess = gus;
    _number = num;
}

void Babylonian::true_root(){
    //(guess + (number/guess))/2 = new guess (repeat)
    _guess =  (_guess + (_number/_guess))/2;
    cout << setprecision(8) << _guess << endl;
    while(true){
        _collector.push_back(_guess);
        _guess = (_guess + (_number/_guess))/2;
        cout << setprecision(9) << _guess << endl;
        if(_collector.back() == _guess){
            _collector.push_back(_guess);
            //cout << setprecision(9) << _guess << endl;
            break;
        }
    }

    /*for(int i; i < _collector.size(); ++i){
        cout << _collector.at(i) << endl;
    }*/

}

