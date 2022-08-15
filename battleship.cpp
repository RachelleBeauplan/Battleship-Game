/********************************
 * Rachelle Beauplan
 * Program: This is War! Battleship game
 * status: Program running succesfully. Also ran successfully on CSEgrid
 ******************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Human.h"
#include "Computer.h"
#include "Board.h"
using namespace std;

int main() {
    srand(time(NULL));

    int menu = 0;
    char play = ' ';
    bool start = true;
    bool gameOn = true;

    while(gameOn){
        cout<< "Welcome to This is war! Battleship game by Rachelle Beauplan. Have fun! "<< endl;
        cout << "To quit the game, please enter 'Q'" << endl;
        cout << "Press 1 to start playing or 2 to quit" << endl;
        if(!(cin >> menu)){
            cin.clear();
            cin.ignore();
            menu = -1;
        }
        switch(menu){
            case 1:
            {
                HumPlayer player1;
                Computer player2;
                start = false;

                while(!start){
                    try{
                        start = player1.filesetupgame();
                    }catch(fileFailedToOpen e){
                        cerr << e.info()<<" "<<e.what();
                        cerr << "Please try again \n";
                        cin >> play;
                        play = toupper(play);
                        if(play == 'Q'){
                            cout << "Thanks for playing\n";
                            exit(0);
                        }
                    }catch(shipsMissing e){
                        player1.printShipBoard();
                        cerr <<"File error\n";
                        cerr << e.info()<< " "<<e.what();
                        cerr << "Please try again \n";
                        cin >> play;
                        play = toupper(play);
                        if(play == 'Q'){
                            cout << "Thank you for playing\n";
                            exit(0);
                        }
                    }
                }
                player2.gameSetup();

                while(!player1.is_Winner() & !player1.is_Winner()){
                    start = false;
                    while(!start){
                        try{
                            start = player1.readyAimFire(player2);
                        }catch(incorrectInput){
                            cerr << "Incorrect input!\n Please make another selection. e.x: A5\n";
                        }
                    }
                    if(player1.is_Winner()){//checks if human won
                        player1.printShotBoard();
                        cout<< "You're the winner!!!\n";
                        start = true;
                        break;
                    }

                    player2.Shoot(player1);
                    player1.printShipBoard();
                    if(player2.is_Winner()){
                        cout<< "You lost!!!!\n";
                        start = true;
                        break;
                    }
                }
                break;
            }

            case 2:
            {
                cout << "GoodBye!\n";
                gameOn = false;
                break;
            }

            default:
            {
                cout<<"Make a different choice";
            }
        }
    }
    return 0;
}

