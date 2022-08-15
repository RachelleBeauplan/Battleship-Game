/************
 *
The fucntion checkBoard will check each location on the board to verify whether it is empty or not.
 Place
PlaceCarries will place the carriers from the input file on the board based whether they should be horizontal or vertical.
 *********/

#include<iostream>
#include "Board.h"
using namespace std;

Board::Board(){
    Row = 10;
    Col = 10;
    std::vector<char> temp;
    for(int i = 0; i < Col; i++)
        temp.push_back(' ');
    for(int j = 0; j < Row; j++)
        board.push_back(temp);
}

bool Board::checkBoard(int row, int col,char mark){
    if (board[row][col] == mark)
        return true;
    else
        return false;
}

void Board::placeCarriers(int row, int col, char mark)
{

    board[row][col] = mark;
}

char Board::getCarriers(int row, int col)
{
    return board[row][col];
}

void Board::printBoard(){ //function to create and print a easily readable grid
    cout << "|    | A | B | C | D | E | F | G | H | I | J ";
    cout << "|\n----------------------------------------------\n";
    for(int row = 0; row < Row; row++){
        if(row < 9){
            std::cout << "| "<< row + 1 << "  ";
        }
        else{
            cout << "| "<< row + 1 << " ";
        }
        for(int col = 0; col < Col; col++){
            cout << "| " << board[row][col] << " ";
        }
        cout <<"|\n----------------------------------------------\n";
    }
}




