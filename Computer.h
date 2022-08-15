//
// Created by Rachelle Beauplan on 12/6/20.
//

#ifndef BSS_TEST_COMPUTER_H
#define BSS_TEST_COMPUTER_H
#include "Player.h"

class Computer:public Player{
private:
    bool torpedoHit;
    bool hitH;
    bool HitV;
    bool hitShipIsSunk;

    int hitRow;
    int hitCol;

public:
    int randindex(){return rand()%10;}

    bool gameSetup();
    bool Shoot(Player &player);

};
#endif //BSS_TEST_COMPUTER_H
