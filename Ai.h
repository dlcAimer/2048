//
// Created by Aliez on 2018/7/7.
//

#ifndef INC_2048_AI_H
#define INC_2048_AI_H

#include "Board.h"

class Ai {
private:
    std::vector<std::string> getLegalMoves(Board &board);
    double getMonotonicity(Board &board) const;
    double evaluation(Board &board);
    double alphaBetaPruning(Board &board, int depth, double alpha, double beta,bool maxPlayer);
public:
    std::string autoMove(Board &board, int depth);
    void autoPlay(Board &board);
};


#endif //INC_2048_AI_H
