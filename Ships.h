//
// Created by Rachelle Beauplan on 12/6/20.
//

#ifndef BSS_TEST_SHIPS_H
#define BSS_TEST_SHIPS_H
#include <string>
#include <vector>
using namespace std;
class Battleships{
private:
    string typeOfShip;
    char mark;
    int lengthOfShip;
    int startingRow;
    int startingCol;
    char direction;
    int hit;
    bool sunk;

public:
    Battleships(){;}
    Battleships(string _typeOfShip);
    ~Battleships(){;}

    string shipType() {return typeOfShip;}
    char shipMark() {return mark;}
    int sizeOfShip() {return lengthOfShip;}
    void setRow(int _startingRow) {startingRow = _startingRow;}
    int getStartRow() {return startingRow;}
    void setCol(int _startingCol) {startingCol = _startingCol;}
    int getStartCol() {return startingCol;}
    char getDirection() {return direction;}
    void setDirection(char _direction){direction = _direction;}
    void setHit(int _hit) {hit = _hit;}
    bool is_sunk(){return sunk;}
    void gotHit();

};
#endif //BSS_TEST_SHIPS_H
