//
// Created by gwdin on 3/31/2022.
//

#ifndef LAB6_BABYLONIAN_H
#define LAB6_BABYLONIAN_H
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
using namespace std;

class Babylonian{
public:
    Babylonian();
    void getter(int num, int gus);
    void true_root();

private:
    float _root;
    float _guess;
    float _number;
    vector<float> _collector;

};


#endif //LAB6_BABYLONIAN_H
