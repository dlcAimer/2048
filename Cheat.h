//
// Created by Aliez on 2018/7/7.
//

#ifndef INC_2048_CHEAT_H
#define INC_2048_CHEAT_H

#include "Board.h"

class Cheat {
public:
    bool shuffleBoard(Board &board);
    bool cleanBlock(Board &board);
};


#endif //INC_2048_CHEAT_H
