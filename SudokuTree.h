//
// Created by ahmad-obeid on 10/14/19.
//

#ifndef SUDOKU_SUDOKUTREE_H
#define SUDOKU_SUDOKUTREE_H


#include <string>
#include "Node.h"
using namespace std;
class SudokuTree {
private:
    Node* head= nullptr;
    Node* tail= nullptr;
    char field[9][9];
public:
    SudokuTree(string x);
    string options(int row,int col);
    void addNode(string s, int row,int col);
    int backtrack(int & x,int &y);
    void solve();

};


#endif //SUDOKU_SUDOKUTREE_H
