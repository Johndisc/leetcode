//
// Created by 58253 on 2023/2/28.
//

#ifndef LEETCODE_N357_H
#define LEETCODE_N357_H
#include "global.h"

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0)
            return 1;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 9;
        int sum = 10;
        for (int i = 2; i <= n; ++i) {
            dp[i] = (11 - i) * dp[i - 1];
            sum += dp[i];
        }
        return sum;
    }
};
#endif //LEETCODE_N357_H
