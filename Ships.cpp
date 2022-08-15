/******
 * Contains the definitions for each battleship and their length
 *
 ****/

#include "Ships.h"
#include <iostream>
#include <cctype>


Battleships::Battleships(string _typeOfShip){
    typeOfShip = _typeOfShip;
    sunk = false;
    hit = 0;
    if(typeOfShip == "CARRIER"){
        lengthOfShip = 5;
        mark = 'C';
    }
    if(typeOfShip == "BATTLESHIP"){
        lengthOfShip = 4;
        mark = 'B';
    }
    if(typeOfShip == "CRUISER"){
        lengthOfShip = 3;
        mark = 'U';
    }
    if(typeOfShip == "SUBMARINE"){
        lengthOfShip = 3;
        mark = 'S';
    }
    if(typeOfShip == "DESTROYER"){
        lengthOfShip = 2;
        mark = 'D';
    }
}

void Battleships::gotHit(){
    std::string shipName;
    shipName = typeOfShip;
    for(int i = 1; i < shipName.size(); i++){
        shipName[i] = tolower(shipName[i]);
    }
    std::cout << std::endl << shipName << " was hit\n";
    hit = hit + 1;
    if(hit == lengthOfShip){
        sunk = true;
    }
}
