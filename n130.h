//
// Created by 58253 on 2023/1/13.
//

#ifndef LEETCODE_N130_H
#define LEETCODE_N130_H
#include "global.h"

class Solution {
public:
    void extendEdge(vector<vector<char>> &board, int i, int j) {
        if (i > 0 && board[i - 1][j] == 'O') {
            board[i - 1][j] = 'P';
            extendEdge(board, i - 1, j);
        }
        if (i < board.size() - 1 && board[i + 1][j] == 'O') {
            board[i + 1][j] = 'P';
            extendEdge(board, i + 1, j);
        }
        if (j > 0 && board[i][j - 1] == 'O') {
            board[i][j - 1] = 'P';
            extendEdge(board, i, j - 1);
        }
        if (j < board[0].size() - 1 && board[i][j + 1] == 'O') {
            board[i][j + 1] = 'P';
            extendEdge(board, i, j + 1);
        }
    }

    void solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            if (board[i][0] == 'O') {
                board[i][0] = 'P';
                extendEdge(board, i, 0);
            }
            if (board[i][board[0].size() - 1] == 'O') {
                board[i][board[0].size() - 1] = 'P';
                extendEdge(board, i, board[0].size() - 1);
            }
        }
        for (int i = 0; i < board[0].size(); ++i) {
            if (board[0][i] == 'O') {
                board[0][i] = 'P';
                extendEdge(board, 0, i);
            }
            if (board[board.size() - 1][i] == 'O') {
                board[board.size() - 1][i] = 'P';
                extendEdge(board, board.size() - 1, i);
            }
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'P')
                    board[i][j] = 'O';
            }
        }
    }
};
#endif //LEETCODE_N130_H
