//
// Created by Aliez on 2018/7/6.
//

#include "Board.h"
#include <iomanip>
#include <cmath>

using namespace std;

bool Board::boardEqual(Board &one) const {
    for (int i = 0; i <ROW ; ++i) {
        for (int j = 0; j < COL; ++j) {
            if(board[i][j] != one.board[i][j]){
                return false;
            }
        }
    }
    return true;
}

void Board::upMove() {
    int flag, temp;
    for (int col = 0; col < 4; col++) {
        for (int row = 0; row < 4; row++) {
            if (board[row][col] != 0) {
                flag = row;
                while (flag != 0 && board[flag - 1][col] == 0) {
                    temp = board[flag - 1][col];
                    board[flag - 1][col] = board[flag][col];
                    board[flag][col] = temp;
                    flag--;
                }
            }
        }
    }
    for (int col = 0; col < 4; col++) {
        for (int row = 0; row < 3; row++) {
            if (board[row][col] == board[row + 1][col]) {
                board[row][col] *= 2;
                board[row + 1][col] = 0;
            }
        }
    }
    for (int col = 0; col < 4; col++) {
        for (int row = 0; row < 4; row++) {
            if (board[row][col] != 0) {
                flag = row;
                while (flag != 0 && board[flag - 1][col] == 0) {
                    temp = board[flag - 1][col];
                    board[flag - 1][col] = board[flag][col];
                    board[flag][col] = temp;
                    flag--;
                }
            }
        }
    }
}

void Board::downMove() {
    int flag, temp;
    for (int col = 0; col < 4; col++) {
        for (int row = 3; row >= 0; row--) {
            if (board[row][col] != 0) {
                flag = row;
                while (flag != 3 && board[flag + 1][col] == 0) {
                    temp = board[flag + 1][col];
                    board[flag + 1][col] = board[flag][col];
                    board[flag][col] = temp;
                    flag++;
                }
            }
        }
    }
    for (int col = 0; col < 4; col++) {
        for (int row = 3; row > 0; row--) {
            if (board[row][col] == board[row - 1][col]) {
                board[row][col] *= 2;
                board[row - 1][col] = 0;
            }
        }
    }
    for (int col = 0; col < 4; col++) {
        for (int row = 3; row >= 0; row--) {
            if (board[row][col] != 0) {
                flag = row;
                while (flag != 3 && board[flag + 1][col] == 0) {
                    temp = board[flag + 1][col];
                    board[flag + 1][col] = board[flag][col];
                    board[flag][col] = temp;
                    flag++;
                }
            }
        }
    }
}

void Board::leftMove() {
    int flag, temp;
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            if (board[row][col] != 0) {
                flag = col;
                while (flag != 0 && board[row][flag - 1] == 0) {
                    temp = board[row][flag - 1];
                    board[row][flag - 1] = board[row][flag];
                    board[row][flag] = temp;
                    flag--;
                }
            }
        }
    }
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row][col] == board[row][col + 1]) {
                board[row][col] *= 2;
                board[row][col + 1] = 0;
            }
        }
    }
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            if (board[row][col] != 0) {
                flag = col;
                while (flag != 0 && board[row][flag - 1] == 0) {
                    temp = board[row][flag - 1];
                    board[row][flag - 1] = board[row][flag];
                    board[row][flag] = temp;
                    flag--;
                }
            }
        }
    }
}

void Board::rightMove() {
    int flag, temp;
    for (int row = 0; row < 4; row++) {
        for (int col = 3; col >= 0; col--) {
            if (board[row][col] != 0) {
                flag = col;
                while (flag != 3 && board[row][flag + 1] == 0) {
                    temp = board[row][flag + 1];
                    board[row][flag + 1] = board[row][flag];
                    board[row][flag] = temp;
                    flag++;
                }
            }
        }
    }
    for (int row = 0; row < 4; row++) {
        for (int col = 3; col > 0; col--) {
            if (board[row][col] == board[row][col - 1]) {
                board[row][col] *= 2;
                board[row][col - 1] = 0;
            }
        }
    }
    for (int row = 0; row < 4; row++) {
        for (int col = 3; col >= 0; col--) {
            if (board[row][col] != 0) {
                flag = col;
                while (flag != 3 && board[row][flag + 1] == 0) {
                    temp = board[row][flag + 1];
                    board[row][flag + 1] = board[row][flag];
                    board[row][flag] = temp;
                    flag++;
                }
            }
        }
    }
}

Board::Board() {
    for (int i = 0; i <ROW ; ++i) {
        for (int j = 0; j <COL ; ++j) {
            board[i][j]=0;
        }
    }
    generateDigital(2);
}

Board::Board(const Board &one) {
    for (int i = 0; i <ROW ; ++i) {
        for (int j = 0; j < COL; ++j) {
            board[i][j] = one.board[i][j];
        }
    }
}

bool Board::generateDigital(int num) {
    bool result = false;
    while (num > 0 && !isFull()) {
        srand(time(0));
        int x = rand() % 4;
        int y = rand() % 4;
        int number = rand() % 10 == 0 ? 4 : 2;
        if (board[x][y] == 0) {
            board[x][y] = number;
            num--;
        }
        result = true;
    }
    return result;
}

void Board::reset() {
    for (int i = 0; i <ROW ; ++i) {
        for (int j = 0; j <COL ; ++j) {
            board[i][j]=0;
        }
    }
    generateDigital(2);
}

bool Board::move(const std::string &order) {
    Board temp(*this);
    if(order=="w"){
        upMove();
    } else if(order=="s"){
        downMove();
    } else if(order=="a"){
        leftMove();
    }else if(order=="d"){
        rightMove();
    }
    return !this->boardEqual(temp);
}

void Board::printBoard() {
    std::cout << "__________________" << std::endl;
    for (int i = 0; i < ROW; i++) {
        cout << "|";
        for (int j = 0; j < COL; j++) {
            string symbol;
            if (board[i][j] == 0) {
                symbol = " ";
            } else {
                symbol = to_string(board[i][j]);
            }
            cout << setw(4) << symbol;
        }
        if (i != 3) {
            cout << "|" << endl;
        } else {
            cout << "|";
        }
    }
    cout << endl << "__________________" << endl;
}

int Board::getEmptyBlocksNum() const {
    int result = 0;
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            if (board[i][j] == 0) result++;
        }
    }
    return result;
}

bool Board::isFull() {
    return getEmptyBlocksNum() == 0;
}

bool Board::isEmpty() {
    return getEmptyBlocksNum() == ROW*COL;
}

bool Board::has2048() {
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            if (board[i][j] == 2048) {
                return true;
            }
        }
    }
    return false;
}

bool Board::isPossibleMove() {
    if(isFull()){
        Board temp(*this);
        if(temp.move("w")){
            return true;
        } else if(temp.move("s")){
            return true;
        } else if(temp.move("a")){
            return true;
        } else return temp.move("d");
    } else {
        return true;
    }
}

vector<int> Board::getBoard() {
    vector<int> result;
    for (int i = 0; i <ROW ; ++i) {
        for (int j = 0; j <COL ; ++j) {
            result.push_back(board[i][j]);
        }
    }
    return result;
}

void Board::setBoard(std::vector<int> source) {
    for (int i = 0; i <ROW ; ++i) {
        for (int j = 0; j <COL ; ++j) {
            board[i][j] = source[i*ROW+j];
        }
    }
}

vector<vector<int>> Board::getNoEmptyBlock() {
    vector<vector<int>> result;
    for (int i = 0; i <ROW ; ++i) {
        for (int j = 0; j <COL ; ++j) {
           if(board[i][j] != 0){
               vector<int> temp;
               temp.push_back(i);
               temp.push_back(j);
               result.push_back(temp);
           }
        }
    }
    return result;
}

int Board::getMaxValue() const {
    int maxValue = 0;
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            if (maxValue < board[i][j]) {
                maxValue = board[i][j];
            }
        }
    }
    return maxValue;
}