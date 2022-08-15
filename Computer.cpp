/*****************
 * These functions allow for the user to play the game. Allow them to fire shots at the board to hit their opponents ship
 ******************/

#include "Computer.h"
#include<iostream>


bool Computer::gameSetup(){
    bool nextShip = false;
    for(int i = 0; i <5;i++){
        nextShip = false;
        while(!nextShip){
            int direction = rand()%2;
            if (direction == 1){
                shipStart(fleet[i], randindex() , randindex(), 'H');
                if(shipNotFound(fleet[i])){
                    placeShip(fleet[i]);
                    nextShip = true;
                }
            }
            else{
                shipStart(fleet[i], randindex(),randindex(), 'V');
                if(shipNotFound(fleet[i])){
                    placeShip(fleet[i]);
                    nextShip = true;
                }
            }
        }
    }
    return true;
}

bool Computer::Shoot(Player &player){
    int row, col, fire;
    bool nextPlayer = false;
    while(!nextPlayer){

        if(torpedoHit){
            row, col +1; row, col - 1;
            row = hitRow;
            col = hitCol;
            row+1, col; row-1, col;

        }
        row = randindex();
        col = randindex();
        fire = firing(row, col, player);
        if(fire == 1){

            torpedoHit = true;
            hitRow = row;
            hitCol = col;
        }
        else if(fire == 0)
        {
            std::cout << "Missed\nYour turn\n";
            nextPlayer = true;
        }
    }
    return nextPlayer;
}