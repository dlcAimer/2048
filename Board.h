//
// Created by Aliez on 2018/7/6.
//

#ifndef INC_2048_BOARD_H
#define INC_2048_BOARD_H

#include <iostream>
#include <vector>

const int COL = 4;
const int ROW = 4;

class Board {
private:
    int board[ROW][COL];
    std::vector<int> getBoard();
    void setBoard(std::vector<int> source);
    bool boardEqual(Board &one) const;
    void upMove();
    void downMove();
    void leftMove();
    void rightMove();
public:
    Board();
    Board(const Board &one);
    ~Board() = default;

    std::vector<std::vector<int>> getNoEmptyBlock();
    int getEmptyBlocksNum() const;
    int getMaxValue() const;
    bool generateDigital(int num);
    bool isFull();
    bool isEmpty();
    void reset();
    bool move(const std::string &order);
    bool has2048();
    bool isPossibleMove();
    void printBoard();

    friend class Cheat;
    friend class Ai;
};


#endif //INC_2048_BOARD_H
