//
// Created by ahmad-obeid on 10/14/19.
//

#ifndef SUDOKU_NODE_H
#define SUDOKU_NODE_H

#include <string>
using namespace std;
class Node {
private:
    char num;
    string options;
    Node* next;
    Node* prev;
    int row,col;

  friend class SudokuTree;
public:
    Node();


};


#endif //SUDOKU_NODE_H
