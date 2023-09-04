/*
    main() function for CSCI 262 Data Structures inheritance lab.
*/
#include <iostream>
#include <vector>
#include "int_counter.h"
#include "mod_counter.h"

using namespace std;

int main() {
    vector<int_counter*> counters;
    counters.push_back(new int_counter);
    counters.push_back(new mod_counter(7));

    string dummy;
    while (true) {
        for (auto cp: counters) {
            cout << cp->to_string() << "\t";
            cp->increment();
        }
        cout << "Enter to continue, r to reset, q to quit ";
        getline(cin, dummy);
        if (dummy == "r") {
            for (auto cp: counters) { cp -> reset(); }
        }
        if (dummy == "q") break;
    }
}
