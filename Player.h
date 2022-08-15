//
// Created by Rachelle Beauplan on 12/6/20.
//

#ifndef BSS_TEST_PLAYER_H
#define BSS_TEST_PLAYER_H

#include <string>
#include "Board.h"
#include "Ships.h"

class Player{
private:
    Board shipBoard;
    Board shotBoard;
    int shipSunk;
    bool winner;

protected:
    vector<Battleships> fleet;

public:
    Player();
    ~Player(){;}

    bool is_Winner(){return winner;}
    Battleships getFleet(int index){return fleet[index];}
    void printShotBoard(){shotBoard.printBoard();}
    void printShipBoard(){shipBoard.printBoard();}
    void shipStart(Battleships &ship, int col, int row, char direction);
    bool shipNotFound(Battleships ship);
    void placeShip(Battleships ship, Board &board1);
    void placeShip(Battleships ship);
    int firing(int row, int col, Player &player1);
};

#endif //BSS_TEST_PLAYER_H
