//
// Created by Rachelle Beauplan on 12/6/20.
//

#ifndef BSS_TEST_BOARD_H
#define BSS_TEST_BOARD_H
#include <vector>
#include <string>
using namespace std;

class Board{
private:
    vector < std::vector<char> > board;
    int Row;
    int Col;
public:
    Board();
    ~Board(){;}


    int getNrow() {return Row;}
    int getNcol() {return Col;}
    bool checkBoard(int row, int col, char mark);
    void placeCarriers(int row, int col, char mark);
    char getCarriers(int row, int col);

    void printBoard();


};
#endif //BSS_TEST_BOARD_H
