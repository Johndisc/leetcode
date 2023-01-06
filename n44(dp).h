//
// Created by 58253 on 2022/8/16.
//

#ifndef LEETCODE_N44_DP_H
#define LEETCODE_N44_DP_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <stack>
#include <map>

using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = p.size(), n = s.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));      //p的前m索引位，s的前n个
        dp[0][0] = true;

        for (int i = 1; i < n + 1; ++i)
            dp[0][i] = false;
        for (int i = 0; i < m; ++i) {
            if (p[i] == '*')
                dp[i + 1][0] = true;
            else
                break;
        }

        for (int i = 1; i < m + 1; ++i) {
            if (p[i - 1] == '?') {
                for (int j = 1; j <= n; ++j)
                    dp[i][j] = dp[i - 1][j - 1];
            }
            else if (p[i - 1] == '*') {
                for (int j = 1; j <= n; ++j)
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            }
            else {
                for (int j = 1; j <= n; ++j)
                    dp[i][j] = (p[i - 1] == s[j - 1]) && dp[i - 1][j - 1];
            }
        }
        for (int i = 0; i < m + 1; ++i) {
            for (int j = 0; j < n + 1; ++j) {
                if (dp[i][j])
                    printf("1 ");
                else
                    printf("0 ");
            }
            printf("\n");
        }
        return dp[m][n];
    }
};
#endif //LEETCODE_N44_DP_H
