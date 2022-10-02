//
// Created by 58253 on 2022/6/19.
//

#ifndef LEETCODE_N36_H
#define LEETCODE_N36_H
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {false};
        bool colum[9][9] = {false};
        bool grid[9][9] = {false};
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.')
                    continue;
                char num = board[i][j] - '0' - 1;
                if (row[i][num])
                    return false;
                row[i][num] = true;
                if (colum[j][num])
                    return false;
                colum[j][num] = true;
                int gridId = (i / 3) * 3 + j / 3;
                if (grid[gridId][num])
                    return false;
                grid[gridId][num] = true;
            }
        }
        return true;
    }
};
#endif //LEETCODE_N36_H
