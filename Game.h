//
// Created by Aliez on 2018/7/6.
//

#ifndef INC_2048_GAME_H
#define INC_2048_GAME_H

#include "Board.h"
#include "Ai.h"
#include "Cheat.h"
#include "Timer.h"
#include "Record.h"
#include "kbhit.h"

class Game {
private:
    Board gameBoard;
    int shuffleToolNum;
    int cleanToolNum;
    bool isGameOver();
    void limit(Timer &timeLimit,int &i);
public:
    Game():shuffleToolNum(5),cleanToolNum(5){}
    ~Game() = default;

    void playGame();
    void restartGame(Timer &timeCounter,Timer &timeLimit, int i);
    void printCheatInfo();
};


#endif //INC_2048_GAME_H
