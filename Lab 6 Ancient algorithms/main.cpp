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
#include "Egyptian.h"
#include "Babylonian.h"

using namespace std;

int main() {
    //std::cout << "Hello, World!" << std::endl
    //Egyptian multiplication
    //The Babylonian Method, use set (since they order it most to least) to check for dups
    int command;
    while(command != 3) { //enter number not name

        cout << "Welcome to Ancient Algorithms" << endl;

        cout << endl << "1.Egyptian_multiplication";
        cout << endl << "2.Babylonian_Method";
        cout << endl << "3.quit" << endl;

        cout << endl << "Enter algorithm: ";
        cin >> command;
        cout << endl;

        if (command == 1) {
            int st;
            int nd;
            cout << "Please enter two positive integers: ";
            cin >> st;
            cin >> nd;
            Egyptian g;
            g.getter(st, nd);
            g.divide_col();
            g.multi_col();
            g.output();
            cout << endl;

        }

        if (command == 2) {
            int guess;
            int number;
            cout << "Enter a number: ";
            cin >> number;
            cout << "What is your guess: ";
            cin >> guess;
            cout << endl;
            Babylonian B;
            B.getter(number, guess);
            B.true_root();
        }
    }

    return 0;
}
