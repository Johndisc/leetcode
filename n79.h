//
// Created by 58253 on 2022/8/8.
//

#ifndef LEETCODE_N79_H
#define LEETCODE_N79_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;
class Solution {
public:
    bool findRes(vector<vector<char>> &board, vector<vector<bool>> &active, int i, int j, string &word, int spos) {
        if (spos == word.size())
            return true;
        active[i][j] = false;
        if (i > 0 && active[i - 1][j] && board[i - 1][j] == word[spos])
            if (findRes(board, active, i - 1, j, word, spos + 1))
                return true;
        if (i < board.size() - 1 && active[i + 1][j] && board[i + 1][j] == word[spos])
            if (findRes(board, active, i + 1, j, word, spos + 1))
                return true;
        if (j > 0 && active[i][j - 1] && board[i][j - 1] == word[spos])
            if (findRes(board, active, i, j - 1, word, spos + 1))
                return true;
        if (j < board[0].size() - 1 && active[i][j + 1] && board[i][j + 1] == word[spos])
            if (findRes(board, active, i, j + 1, word, spos + 1))
                return true;
        active[i][j] = true;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int pos = 0;
        vector<vector<bool>> active(board.size(), vector<bool>(board[0].size(), true));

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) {
                    if (findRes(board, active, i, j, word, 1))
                        return true;
                }
            }
        }
        return false;
    }
};
#endif //LEETCODE_N79_H
