//
// Created by Aliez on 2018/7/7.
//

#include <cmath>
#include "Ai.h"

using namespace std;

vector<string> Ai::getLegalMoves(Board &board) {
    vector<string> result;
    Board wTest(board);
    Board sTest(board);
    Board aTest(board);
    Board dTest(board);
    wTest.move("w");
    sTest.move("s");
    aTest.move("a");
    dTest.move("d");
    if(!board.boardEqual(wTest)){
        result.push_back("w");
    }
    if(!board.boardEqual(sTest)){
        result.push_back("s");
    }
    if(!board.boardEqual(aTest)){
        result.push_back("a");
    }
    if(!board.boardEqual(dTest)){
        result.push_back("d");
    }
    return result;
}

double Ai::getMonotonicity(Board &board) const {
    int totals[] = {0, 0, 0, 0};
    for (int j = 0; j < 4; j++) {
        int current = 0;
        int next = current + 1;
        while (next < 4) {
            while (next < 4 && board.board[next][j] == 0) next++;
            if (next >= 4) next--;
            double currentValue = (board.board[current][j] != 0) ? log(board.board[current][j]) / log(2) : 0;
            double nextValue = (board.board[next][j] != 0) ? log(board.board[next][j]) / log(2) : 0;
            if (currentValue > nextValue) {
                totals[2] += nextValue - currentValue;
            } else if (nextValue > currentValue) {
                totals[3] += currentValue - nextValue;
            }
            current = next;
            next++;
        }
    }
    for (int i = 0; i < 4; i++) {
        int current = 0;
        int next = current + 1;
        while (next < 4) {
            while (next < 4 && board.board[i][next] == 0) next++;
            if (next >= 4) next--;
            double currentValue = (board.board[i][current] != 0) ? log(board.board[i][current]) / log(2) : 0;
            double nextValue = (board.board[i][next] != 0) ? log(board.board[i][next]) / log(2) : 0;
            if (currentValue > nextValue) {
                totals[0] += nextValue - currentValue;
            } else if (nextValue > currentValue) {
                totals[1] += currentValue - nextValue;
            }
            current = next;
            next++;
        }
    }
    return max(totals[0], totals[1]) + max(totals[2], totals[3]);
}

double Ai::evaluation(Board &board) {
    double monoWeigtht=1.0;
    double emptyWeight=3;
    double maxWeight=1.0;
    return monoWeigtht*getMonotonicity(board)+emptyWeight*log(board.getEmptyBlocksNum())+
            maxWeight*(log(board.getMaxValue())/log(2));
}

double Ai::alphaBetaPruning(Board &board, int depth, double alpha, double beta, bool maxPlayer) {
    if (depth == 0) {
        return evaluation(board);
    }
    if (maxPlayer) {
        double bestmove = -9999;
        Board prev(board);
        for (int i = 0; i < getLegalMoves(board).size(); i++) {
            board.move(getLegalMoves(board)[i]);
            bestmove = max(bestmove, alphaBetaPruning(board,depth - 1,alpha, beta, false));
            board=prev;
            if (alpha < bestmove){
                alpha = bestmove;
                if (alpha >= beta)
                    break;
            }

        }
        return bestmove;
    }
    else{
        double bestmove = 9999;
        Board prev(board);
        for (int i = 0; i <16; i++) {
            board.generateDigital(1);
            bestmove = min(bestmove, alphaBetaPruning(board,depth - 1,alpha, beta, true));
            board=prev;
            if (bestmove<beta){
                beta=bestmove;
                if (alpha>=beta)
                    break;
            }
        }
        return bestmove;
    }
}

string Ai::autoMove(Board &board, int depth) {
    double best_move_val=-9999;
    double bestmove=0;
    string result;
    Board temp(board);
    for(int i=0;i<getLegalMoves(board).size();i++) {
        board.move(getLegalMoves(board)[i]);
        bestmove = alphaBetaPruning(board, depth - 1,-9999, 9999 , false);
        board=temp;
        if (bestmove >= best_move_val){
            best_move_val = bestmove;
            result= getLegalMoves(board)[i];
        }
    }
    return result;
}

void Ai::autoPlay(Board &board) {
    string move = autoMove(board,5);
    board.move(move);
    board.generateDigital(1);
    cout << "AI: " << move << endl;
}
