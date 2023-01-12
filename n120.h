//
// Created by 58253 on 2023/1/12.
//

#ifndef LEETCODE_N120_H
#define LEETCODE_N120_H
#include "global.h"

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>& dp(triangle);
        int level = triangle.size();
        for (int i = level - 2; i >= 0; --i) {
            for (int j = 0; j < i + 1; ++j) {
                dp[i][j] = triangle[i][j] + min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return dp[0][0];
    }
};
#endif //LEETCODE_N120_H
