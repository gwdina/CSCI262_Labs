//
// Created by gwdin on 3/29/2022.
//

#ifndef LAB6_EGYPTIAN_H
#define LAB6_EGYPTIAN_H

#endif //LAB6_EGYPTIAN_H

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
using namespace std;

class Egyptian{
public:
    Egyptian();
    void getter(int st, int nd);
    void divide_col();
    void multi_col();
    void output();

private:
    int _num1;
    int _num2;
    vector<int> _multi;
    vector<int> _divide;

};