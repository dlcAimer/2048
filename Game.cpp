//
// Created by Aliez on 2018/7/6.
//

#include "Game.h"

using namespace std;

void Game::printCheatInfo() {
    cout << "You have " << shuffleToolNum << " shuffle tool and " << cleanToolNum << " clean tool " << endl;
}

bool Game::isGameOver() {
    return (!gameBoard.isPossibleMove())||gameBoard.has2048();
}

void Game::restartGame(Timer &timeCounter,Timer &timeLimit, int i) {
    cout << " enter r to restart, enter other go back the main menu" << endl;
    string tempOrder;
    cin >> tempOrder;
    if (tempOrder == "r") {
        timeCounter.restart();
        timeLimit.restart();
        gameBoard.reset();
        gameBoard.printBoard();
        i = 1;
    } else {
        return;
    }
}

void Game::limit(Timer &timeLimit, int &i) {
    while(!kbhit()){
        if(timeLimit.getUsingTime()>=15*i){
            if(gameBoard.generateDigital(1)){
                cout<<"You've been thinking too long "<<endl;
                cout<<"A penalty block is given"<<endl;
                gameBoard.printBoard();
                timeLimit.print();
                i++;
            }
        }
    }
}

void Game::playGame() {
    cout << " 1. enter w/s/a/d to play the game. " << endl;
    cout << " 2. enter r to start" << endl;
    cout << " 3. enter z to shuffle the board " << endl;
    cout << " 4. enter x clean a block " << endl;
    cout << " 5. enter c to begin a automatical game" << endl;
    cout << " 6. if you want to back to the main menu enter quit" << endl;
    cout << " good luck!" << endl;

    string order;
    gameBoard.printBoard();
    Timer timeCounter;
    Timer timeLimit;
    Cheat cheatTool;
    Record record;
    record.load();

    int i = 1;
    while (true) {
        printCheatInfo();
        limit(timeLimit, i);

        cin >> order;
        if (order == "quit") {
            break;
        } else if (order == "c") {
            while (!isGameOver()){
                Ai zz;
                zz.autoPlay(gameBoard);
                gameBoard.printBoard();
                timeLimit.print();
                timeLimit.restart();
            }
            restartGame(timeCounter,timeLimit,i);
        } else if (order == "r") {
            timeCounter.restart();
            timeLimit.restart();
            gameBoard.reset();
            gameBoard.printBoard();
            i = 1;
            continue;
        } else if (order == "z") {
            timeLimit.restart();
            if (shuffleToolNum > 0) {
                shuffleToolNum--;
                cheatTool.shuffleBoard(gameBoard);
                cout << "you have used the shuffle tool!" << endl;
                gameBoard.printBoard();
            } else {
                cout << "you don't have a shuffle tool" << endl;
            }
        } else if (order == "x") {
            timeLimit.restart();
            if (cleanToolNum > 0) {
                if (cheatTool.cleanBlock(gameBoard)) {
                    cleanToolNum--;
                    cout << "a block has been cleaned" << endl;
                    gameBoard.printBoard();
                }
            } else {
                cout << "you don't have a clean tool" << endl;
            }
        }
        if (gameBoard.move(order)) {
            gameBoard.generateDigital(1);
            gameBoard.printBoard();
            timeLimit.print();
            timeLimit.restart();
            i = 1;
        }
        if (isGameOver()) {
            if (gameBoard.has2048()) {
                record.add(timeCounter.getUsingTime());
                cout << "you win this game ! you can look up your record in the records list" << endl;
            } else {
                cout << "you lose this game please try again" << endl;
            }
            restartGame(timeCounter,timeLimit,i);
        }
    }
}