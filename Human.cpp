/******************
 * the functions will setup the game for the human player and allow them to play.
 * Let's them decide where they would like to shoot. Player will continue playing until they miss then computer gets a turn.
 * it will run contiously until the player quits
 */

#include "Human.h"
#include<iostream>
#include <fstream>
using namespace std;

bool HumPlayer::filesetupgame() throw(shipsMissing){
    string shipName, location, direction;
    bool complete = false;
    int startingRow, startingCol;
    const char *direct;
    const char *startPosition;
    char tempChar, tempDirection;

    ifstream infile("ship_placement.csv");

    if(infile.fail()){
        cout << "File cannot open";
    }
    getline(infile, shipName);
    while(getline(infile, shipName, ',')){
        for(int i = 0; i < shipName.length(); i++){
            shipName[i] = toupper(shipName[i]);
        }
        getline(infile, location, ',');
        getline(infile, direction);
        if(shipName == "" || location == ""|| direction == ""){
            throw shipsMissing(shipName);
        }


        direction = direction.c_str();
        tempDirection = direction[0];
        tempDirection = toupper(tempDirection);
        startPosition = location.c_str();
        tempChar = startPosition[0];
        startingCol = convert(tempChar);
        startingRow = startPosition[1] - 49;
        if(location.size() > 2){
            if(startPosition[1] == 49 & startPosition[2] == 48)
                startingRow = 9;
            else
                startingRow = -1;
        }
        if(startingCol == -1 || startingRow < 0 || startingRow > 9 || (tempDirection != 'H' & tempDirection != 'V')){//checks input for correct indexs
            throw shipsMissing(shipName);
        }
        for(int i = 0; i<5 ; i++){
            if(fleet[i].shipType() == shipName){
                shipStart(fleet[i], startingCol, startingRow, tempDirection);
                if(shipNotFound(fleet[i])){
                    placeShip(fleet[i]);
                    shipsPlaced++;
                }
                else{
                    throw shipsMissing(shipName);
                }
            }
        }
    }
    if(shipsPlaced == 5)
    {
        complete = true;
    }
    else{
        throw shipsMissing("A");
    }
    cout << "Player Ship Board\n";
    printShipBoard();
    infile.close();
    return complete;
}

bool HumPlayer::readyAimFire(Player &player) throw (incorrectInput){
    int row = -1, fire, numCol;
    char col;
    bool nextPlayer = false;
    while(!nextPlayer){
        printShotBoard();
        cout <<"Enter the coordinates of where you want to shoot. E.x. A5: \n";
        cin >> col;
        if(!isalpha(col)){
            throw incorrectInput();
        }
        col = toupper(col);
        if(col == 'Q'){
            cout << "Thanks for playing!\n Your final Board:\n";
            printShotBoard();
            cout << "Computer's final board\n";
            player.printShipBoard();
            exit(1);
        }
        if(!(cin >> row)){
            cin.clear();
            throw incorrectInput();
        }
        numCol = convert(col);
        if( !( 1 <= row & row <= 10) || numCol == -1){
            throw incorrectInput();
        }
        fire = firing(row - 1, numCol, player);
        if(fire == 0){
            cout << "MISS!!!!\n It's the computer's Turn\n";
            nextPlayer = true;
        }
        else if(fire == 2){
            cout << "Duplicate shot\n";
            cout << "Please Try Again: \n";
        }
        else if(fire == 3){//winner
            return true;
        }
    }
    return nextPlayer;
}


int HumPlayer::convert(char col){
    int numCol = -1;
    col = toupper(col);
    switch(col){
        case 'A':
            numCol = 0;
            break;
        case 'B':
            numCol = 1;
            break;
        case 'C':
            numCol = 2;
            break;
        case 'D':
            numCol = 3;
            break;
        case 'E':
            numCol = 4;
            break;
        case 'F':
            numCol = 5;
            break;
        case 'G':
            numCol = 6;
            break;
        case 'H':
            numCol = 7;
            break;
        case 'I':
            numCol = 8;
            break;
        case 'J':
            numCol = 9;
            break;
        default:
            numCol = -1;
    }
    return numCol;
}