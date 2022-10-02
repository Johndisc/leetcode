//
// Created by 58253 on 2022/6/20.
//

#ifndef LEETCODE_N37_H
#define LEETCODE_N37_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;
class Solution {
public:
    bool row[9][10] = {false};
    bool colum[9][10] = {false};
    bool grid[9][10] = {false};

    bool rec(vector<vector<char>>& res, int i, int j) {
        int ni = i, nj = j;
        ni += (nj + 1) / 9;
        nj = (nj + 1) % 9;
        while (ni * 9 + nj <= 80) {
            if (res[ni][nj] == '.')
                break;
            else
            {
                ni += (nj + 1) / 9;
                if (ni==9)
                    break;
                nj = (nj + 1) % 9;
            }
        }
        for (int k = 1; k <= 9; ++k) {
            if (!row[i][k] && !colum[j][k] && !grid[(i / 3) * 3 + j / 3][k]) {
                res[i][j] = '0' + k;
                row[i][k] = true;
                colum[j][k] = true;
                grid[(i / 3) * 3 + j / 3][k] = true;
                if (ni==9)
                    return true;
                if (rec(res, ni, nj))
                    return true;
                row[i][k] = false;
                colum[j][k] = false;
                grid[(i / 3) * 3 + j / 3][k] = false;
                res[i][j] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.')
                    continue;
                int num = board[i][j] - '0';
                row[i][num] = true;
                colum[j][num] = true;
                int gridId = (i / 3) * 3 + j / 3;
                grid[gridId][num] = true;
            }
        }
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    if (rec(board, i, j))
                        return;
                }
            }
        }
    }
};
#endif //LEETCODE_N37_H
