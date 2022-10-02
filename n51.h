//
// Created by 58253 on 2022/7/5.
//

#ifndef LEETCODE_N51_H
#define LEETCODE_N51_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;
class Solution {
public:
    vector<vector<string>> res;
    vector<string> field;

    bool check(int i, int j, int n) {
        for (int k = 0; k < n; ++k) {
            if (field[i][k] == 'Q')
                return false;
            if (field[k][j] == 'Q')
                return false;
            if (j - (i - k) >= 0 && j - (i - k) < n)
                if (field[k][j - (i - k)] == 'Q')
                    return false;
            if (j + (i - k) < n && j + (i - k) >= 0)
                if (field[k][j + (i - k)] == 'Q')
                    return false;
        }
        return true;
    }
    void findRes(int row, int n) {
        if (row == n) {
            res.push_back(field);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (check(row, i, n)) {
                field[row][i] = 'Q';
                findRes(row + 1, n);
                field[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        for (int i = 0; i < n; ++i)
            field.emplace_back(n, '.');
        findRes(0, n);
        return res;
    }
};
#endif //LEETCODE_N51_H
