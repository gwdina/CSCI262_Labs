//
// Created by gwdin on 3/29/2022.
//
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>

#include "Egyptian.h"

Egyptian::Egyptian(){
    _num1;
    _num2;
    _multi;
    _divide;
}

void Egyptian::getter(int st, int nd){
    _num1 = st;
    _num2 = nd;
}

void Egyptian::divide_col(){
    _divide.push_back(_num1);
    while(_num1 != 1){
        _num1 = _num1 / 2;
        _divide.push_back(_num1);
    }

}

void Egyptian::multi_col(){
    _multi.push_back(_num2);
    for(int i=0; i < _divide.size()-1; ++i){
        _num2 = _num2 * 2;
        _multi.push_back(_num2);
    }


}

void Egyptian::output(){
    int sum;
    for(int j=0; j < _divide.size(); ++j){
        cout << setw(2) << _divide.at(j) << setw(5) << _multi.at(j);
        cout << endl;
    }
    for(int j=0; j < _divide.size(); ++j){
        if((_divide.at(j) % 2 == 0) && (_multi.at(j) % 2 == 0)){
            _divide.erase(_divide.begin()+j);
            _multi.erase(_multi.begin()+j);
        }
    }

    for(int i=0; i < _multi.size(); ++i){
        sum += _multi.at(i);
    }
    cout << endl << "Answer: " << sum << endl;

}



