/*
 * editor.cpp
 *
 * Author: <your name here>
 *
 * Implementation code for the editor class.
 *
 * Last modified: 1/20/2022
 */

#include <iostream>

#include "editor.h"

using namespace std;

bool editor::execute(picture &p, const string &command) {
    if (command == "negate") _negate(p);
    else if (command == "grayscale") {
        _grayscale(p);
    }
    // when the input command is "grayscale"
    else {
        cout << "Unknown command: " << command << endl;
        return false;
    }

    return true;
}

void editor::_negate(picture &p) {
    int w = p.width();
    int h = p.height();

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            p.set(x, y, 255 - p.red(x, y), 255 - p.green(x, y), 255 - p.blue(x, y));
        }
    }
}

void editor::_grayscale(picture &p) {
    int w = p.width();
    int h = p.height();

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            p.set(x, y, (p.red(x, y) + p.green(x, y) + p.blue(x, y))/3, (p.red(x, y) + p.green(x, y) + p.blue(x, y))/3, (p.red(x, y) + p.green(x, y) + p.blue(x, y))/3);
        }
    }
}