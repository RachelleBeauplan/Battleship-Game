/***************
 *
 * checking if game is ready to be played and all the battleships are on the board  and in the correct spot.
 */

#include "Player.h"
#include <iostream>
#include <cctype>
using namespace std;


Player::Player(){
    winner = false;
    shipSunk = 0;
    Battleships carrier("CARRIER");
    Battleships battleship("BATTLESHIP");
    Battleships cruiser("CRUISER");
    Battleships submarine("SUBMARINE");
    Battleships destroyer("DESTROYER");

    fleet.push_back(carrier);
    fleet.push_back(battleship);
    fleet.push_back(cruiser);
    fleet.push_back(submarine);
    fleet.push_back(destroyer);
}

void Player::shipStart(Battleships &ship, int col, int row, char direction)
{
    ship.setCol(col);
    ship.setRow(row);
    ship.setDirection(direction);
}


bool Player::shipNotFound(Battleships ship){
    bool notHere = true;
    if(!(shipBoard.checkBoard(ship.getStartRow(), ship.getStartCol(), ' '))){
        notHere = false;
        return notHere;
    }
    if(ship.getDirection() == 'H'){
        if((ship.getStartCol() + ship.sizeOfShip()) > shipBoard.getNcol()){
            notHere = false;
            return notHere;
        }
        for(int i = 0; i < ship.sizeOfShip(); i++){
            notHere = shipBoard.checkBoard(ship.getStartRow(),ship.getStartCol() + i, ' ');
            if(!notHere){
                return notHere;
            }
        }
    }
    if(ship.getDirection() == 'V'){
        if((ship.getStartRow() + ship.sizeOfShip()) > shipBoard.getNrow()){
            notHere = false;
            return notHere;
        }
        for(int i = 0; i < ship.sizeOfShip(); i++){
            notHere = shipBoard.checkBoard(ship.getStartRow() + i, ship.getStartCol(), ' ');
            if(!notHere){
                return notHere;
            }
        }
    }
    return notHere;
}

void Player::placeShip(Battleships ship){
    if(ship.getDirection() == 'H'){
        for(int i = 0; i < ship.sizeOfShip(); i++)
            shipBoard.placeCarriers(ship.getStartRow(),ship.getStartCol() + i, ship.shipMark());
    }
    if(ship.getDirection() == 'V'){
        for(int i = 0; i < ship.sizeOfShip(); i++)
            shipBoard.placeCarriers(ship.getStartRow() + i, ship.getStartCol(), ship.shipMark());
    }
}


void Player::placeShip(Battleships ship, Board &board1){
    if(ship.getDirection() == 'H'){
        for(int i = 0; i < ship.sizeOfShip(); i++)
            board1.placeCarriers(ship.getStartRow(),ship.getStartCol() + i, ship.shipMark());
    }
    if(ship.getDirection() == 'V'){
        for(int i = 0; i < ship.sizeOfShip(); i++)
            board1.placeCarriers(ship.getStartRow() + i, ship.getStartCol(), ship.shipMark());
    }
}

int Player::firing(int row, int col, Player &player) {
    std::string shipName;
    int result = -1;
    if (!shotBoard.checkBoard(row, col,
                             ' ')) {
        return 2;
    } else if (player.shipBoard.checkBoard(row, col, ' ')) {
        shotBoard.placeCarriers(row, col, 'O');
        return 0;
    } else {
        for (int i = 0; i <
                        player.fleet.size(); i++) {
            if (player.shipBoard.checkBoard(row, col,
                                           player.fleet[i].shipMark())) {
                player.fleet[i].gotHit();
                player.shipBoard.placeCarriers(row, col, 'X');
                shotBoard.placeCarriers(row, col, 'X');
                if (player.fleet[i].is_sunk()) {
                    placeShip(player.fleet[i], shotBoard);
                    shipSunk++;
                    shipName = player.fleet[i].shipType();
                    for (int i = 1; i < shipName.size(); i++) {
                        shipName[i] = tolower(shipName[i]);
                    }
                    std::cout << std::endl << shipName << " is sunk!\n";
                    if (shipSunk == 5) {
                        winner = true;
                        return 3;
                    }
                }
                return 1;
            }
        }
    }
    return result;
}