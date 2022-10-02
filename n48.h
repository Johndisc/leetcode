//
// Created by 58253 on 2022/7/5.
//

#ifndef LEETCODE_N48_H
#define LEETCODE_N48_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int temp;
        for (int i = 0; i < (matrix.size() + 1) / 2; ++i) {
            for (int j = i; j < i + matrix.size() - 2 * i-1; ++j) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[matrix.size() - j - 1][i];
                matrix[matrix.size() - j - 1][i] = matrix[matrix.size() - i - 1][matrix.size() - j - 1];
                matrix[matrix.size() - i - 1][matrix.size() - j - 1] = matrix[j][matrix.size() - i - 1];
                matrix[j][matrix.size() - i - 1] = temp;
            }
        }
    }
};
#endif //LEETCODE_N48_H
