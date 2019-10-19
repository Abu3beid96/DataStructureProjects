//
// Created by ahmad-obeid on 10/14/19.
//

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm> // for std::find
#include <iterator>
#include "SudokuTree.h"
using namespace std;

SudokuTree::SudokuTree(string s) {

    ifstream inFile(s);
    if (inFile.fail())
        cout << "error opening the file";
    else {

        char y[81];
        inFile >> y;

        int index = 0;
        for (int i = 0; i < 9; i++)
            for (int t = 0; t < 9; t++) {
                field[i][t] = y[index];
                index++;

            }

    }

}

string SudokuTree::options(int x, int y) {

    char arr[27];
    int t = 0;


    if (x>=0 && x<=2 && y>=0 && y<=2) {

        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j <= 2; j++) {
                if (field[i ][j] != '0') {
                    arr[t] = field[i][j];
                    

                  
                    t++;
                }

            }
        }
    }


    if (x >= 0 && x <= 2 && y >= 3 && y <= 5) {

        for (int i = 0; i <= 2; i++) {
            for (int j = 3; j <= 5; j++) {
                if (field[i][j] != '0') {
                    arr[t] = field[i][j];
                     
                  
                    t++;
                }
            }
        }

    }



    if (x >= 0 && x <= 2 && y >= 6 && y <= 8) {

        for (int i = 0; i <= 2; i++) {
            for (int j = 6; j <= 8; j++) {
                if (field[i][j] != '0') {
                    arr[t] = field[i][j];
                     
                  
                    t++;
                }
            }
        }

    }





    if (x >= 3 && x <= 5 && y >= 0 && y <= 2) {

        for (int i = 3; i <= 5; i++) {
            for (int j = 0; j <= 2; j++) {
                if (field[i][j] != '0') {
                    arr[t] = field[i][j];
                     
                  
                    t++;
                }
            }
        }

    }




    if (x >= 3 && x <= 5 && y >= 3 && y <= 5) {

        for (int i = 3; i <= 5; i++) {
            for (int j = 3; j <= 5; j++) {
                if (field[i][j] != '0') {
                    arr[t] = field[i][j];
                     
                  
                    t++;
                }
            }
        }

    }




    if (x >= 3 && x <= 5 && y >= 6 && y <= 8) {

        for (int i = 3; i <= 5; i++) {
            for (int j = 6; j <= 8; j++) {
                if (field[i][j] != '0') {
                    arr[t] = field[i][j];
                     
                  
                    t++;
                }
            }
        }

    }




    if (x >= 6 && x <= 8 && y >= 0 && y <= 2) {

        for (int i = 6; i <= 8; i++) {
            for (int j = 0; j <= 2; j++) {
                if (field[i][j] != '0') {
                    arr[t] = field[i][j];
                     
                  
                    t++;
                }
            }
        }

    }



    if (x >= 6 && x <= 8 && y >= 3 && y <= 5) {

        for (int i = 6; i <= 8; i++) {
            for (int j = 3; j <= 5; j++) {
                if (field[i][j] != '0') {
                    arr[t] = field[i][j];
                     
                  
                    t++;
                }
            }
        }

    }

    if (x >= 6 && x <= 8 && y >= 6 && y <=8) {

        for (int i = 6; i <= 8; i++) {
            for (int j = 6; j <= 8; j++) {
                if (field[i][j] != '0') {
                    arr[t] = field[i][j];
                     
                  
                    t++;
                }
            }
        }

    } // end of 



    for (int i = 0; i < 9; i++) {
        if (field[x][i] != '0') {
            arr[t] = field[x][i];
            t++;
        }
    }

    for (int j = 0; j < 9; j++) {
        if (field[j][y] != '0') {
            arr[t] = field[j][y];
            t++;
        }

    }


string f="";
bool flag=false;

 for(int i=1;i<=9;i++){
     char a=i+'0';
     for(int j=0;j<27;j++){
         if(a==arr[j]) {
             flag = true;
         }
     }
     if(!flag){f+=a;}
     flag =false;
 }

return f;
}


void SudokuTree::addNode(string s,int row, int col){
    Node* link= new Node();
    link->options=s;
    link->row=row;
    link->col=col;
    link->num=s[0];
    if(s.length()==0)
        link->num='$';

   field[row][col]=(link->num);
    if(head== nullptr){
        head=link;
        tail=link;
    }else{

        tail->next=link;
        link->prev=tail;
        tail=link;
    }

}
int SudokuTree:: backtrack(int & x,int &y){

    while(true) {

        if (tail->num== tail->options.back() ){
          //  Node *temp = tail;
            field[tail->row][tail->col]='0';

            tail = tail->prev;
        if(tail== nullptr){
            cout<<"No Solution Found";
            return 0;
        }

        }
        else{

            tail->num=tail->options[tail->options.find(tail->num)+1];
            field[tail->row][tail->col]=tail->num;
            x=tail->row;
            y=tail->col;
            return 1;
        }
    }




   }

void SudokuTree:: solve(){
    int j=0;
    for (int i = 0; i < 9; i++) {
        for (;j < 9; j++) {
            if (field[i][j] == '0') {
                string op = options(i, j);
                cout<<'\n';
               if(op.length()!=0){addNode(op, i, j);}
               else{
                   int x=0,y=0;
                   if(!backtrack(x,y)) return;
                   i=x;j=y;
               }

            }
        }
        j=0;
    }
    for (int i = 0; i < 9; i++){
        for (int k = 0; k<9;k++) {
            cout<<field[i][k]<<" ";
        }
        cout<<"\n";}

}
