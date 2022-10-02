//
// Created by 58253 on 2022/8/6.
//

#ifndef LEETCODE_N73_H
#define LEETCODE_N73_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> row(m, false);
        vector<bool> colum(n, false);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    row[i] = true;
                    colum[j] = true;
                }
            }
        }
        for (int i = 0; i < m; ++i)
            if (row[i])
                for (int j = 0; j < n; ++j)
                    matrix[i][j] = 0;
        for (int i = 0; i < n; ++i)
            if (colum[i])
                for (int j = 0; j < m; ++j)
                    matrix[j][i] = 0;
    }
};
#endif //LEETCODE_N73_H
