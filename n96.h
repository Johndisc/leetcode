//
// Created by 58253 on 2023/1/3.
//

#ifndef LEETCODE_N96_H
#define LEETCODE_N96_H
#include "global.h"

class Solution {
public:
    int numTrees(int n) {
        int dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = 0;
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};
#endif //LEETCODE_N96_H
