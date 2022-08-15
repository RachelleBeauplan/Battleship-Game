//
// Created by Rachelle Beauplan on 12/6/20.
//

#ifndef BSS_TEST_HUMAN_H
#define BSS_TEST_HUMAN_H
#include "Player.h"
#include <exception>
#include <string>
#include <fstream>
using namespace std;

class fileFailedToOpen:public exception{
private:
    std::string fileName;
public:
    fileFailedToOpen(string _fileName){fileName = _fileName;}
    string info() const {return fileName;}
    const char* what() const noexcept {return "File error! Cannot open!\n";}
};

class shipsMissing:public std::exception{
private:
    std::string shipName;
public:
    shipsMissing(string _shipName){shipName = _shipName;}
    string info() const {return shipName;}
    const char* what() const noexcept {return "ship was not placed!\n";}
};

class incorrectInput:public exception{
public:
    incorrectInput(){;}
    const char* what() const noexcept {return "Wrong Input!\n";}
};

class HumPlayer:public Player{
private:
    int convert(char col);
    int shipsPlaced = 0;

public:

    bool filesetupgame () throw (shipsMissing);
    bool readyAimFire(Player &player) throw (incorrectInput);
};



#endif //BSS_TEST_HUMAN_H
