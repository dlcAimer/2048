//
// Created by Aliez on 2018/7/7.
//

#include <vector>
#include <random>
#include "Cheat.h"

using namespace std;

bool Cheat::shuffleBoard(Board &board) {
    vector<int> temp = board.getBoard();
    Board tempBoard(board);
    while (tempBoard.boardEqual(board)){
        shuffle(temp.begin(),temp.end(), mt19937(random_device()()));
        board.setBoard(temp);
    }
    return true;
}

bool Cheat::cleanBlock(Board &board) {
    if(!board.isEmpty()) {
        vector<vector<int>> temp;
        temp = board.getNoEmptyBlock();
        srand(time(0));
        int position = rand() % temp.size();
        board.board[temp[position][0]][temp[position][1]] = 0;
        return true;
    }
    cout<<"no block can be clean"<<endl;
    return false;
}
