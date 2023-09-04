/*
 * main.cpp
 *
 * starter code for the Binary Tree lab, CSCI 262
 *
 * last modified: 3/10/2020
 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class node
{
public:
    string data;
    node *left;
    node *right;
};
node *reading(ifstream &in)
{ // builds trees in pre-order traversal
    string word;
    string tree;
    in >> word >> tree;
    node *head;
    head = new node;
    head->data = word;
    if ((tree == "L") || (tree == "LR"))
    {
        head->left = reading(in);
    }
    else
    {
        head->left = nullptr;
    }
    if ((tree == "R") || (tree == "LR"))
    {
        head->right = reading(in);
    }
    else
    {
        head->right = nullptr;
    }
    if (tree == "N")
    {
        head->left = nullptr;
        head->right = nullptr;
    }
    return head;
}
string ad_string(node *tree)
{ // takes tree and reads it, then forms into string
    string building = "";
    if (tree != nullptr)
    {
        building = building + tree->data + " ";
        building = ad_string(tree->left) + building;                                           // grabs left side of tree and
        throws it on the left side of "building" building = building + ad_string(tree->right); // grabs right side of tree
        and throws it on the right side of "building"
    }
    return building;
} //
bool contains(string text, node *tree)
{ // will go over the binary tree to see if the
    word inputted is in said tree if (tree == nullptr)
    { // if it reaches the end that means no word was found
        return false;
    }
    else
    {
        return text == tree->data || contains(text, tree->left) || contains(text, tree->right);
    }
}
// This program is simple enough to do the user interface in main()
int main()
{
    string input_filename;
    cout << "What is the file you wish to read?" << endl;
    cin >> input_filename;
    ifstream fin(input_filename);
    if (!fin)
    {
        cout << "Error opening \"" << input_filename << "\" for reading." << endl;
        return -1;
    }
    node *tree = reading(fin);
    fin.close();
    cout << ad_string(tree) << endl;
    string testing;
    cout << "Enter word to check if it's in the binary tree: ";
    cin >> testing;
    bool facts = contains(testing, tree);
    if (facts == true)
    {
        cout << endl
             << "Word is in binary tree.";
    }
    else
    {
        cout << endl
             << "Word is not in binary tree.";
    }
    return 0;
}