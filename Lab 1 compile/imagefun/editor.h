/*
 * editor.h
 *
 * Author: <your name here>
 *
 * Apply various image filters to PNG image files.
 *
 * Last modified: 1/20/2022
 */

#ifndef _EDITOR_H
#define _EDITOR_H

#include "tool.h"

using namespace std;

class editor : public tool {
public:
    // return the utility commands and utility descriptions for the functions
    // provided by this tool
    vector<string> get_verbs() override {
        return {
            "negate",
            "grayscale"
        };
    }

    vector<string> get_menu_entries() override {
        return {
            "Negate colors in current picture",
            "Transform current picture to grayscale"
        };
    }

    // perform a command provided by this tool, return true if the command
    // modifies the picture passed in argument p
    bool execute(picture &p, const string &command) override;

    editor() = default;

private:
    void _negate(picture &p);
    void _grayscale(picture &p);
};

#endif
