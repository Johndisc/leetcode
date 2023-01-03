//
// Created by 58253 on 2022/8/18.
//

#ifndef LEETCODE_N97_DP_H
#define LEETCODE_N97_DP_H
#include "global.h"

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.empty() && s2.empty() && s3.empty())
            return true;
        int m = s1.size(), n = s2.size();
        if (m + n != s3.size())
            return false;
        if ((s1.empty() && s2 == s3) || (s2.empty() && s1 == s3))
            return true;
        bool dp[m + 1][n + 1];
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = false;
            }
        }
        for (int i = 0; i < m; ++i) {
            if (s1[i] == s3[i])
                dp[i + 1][0] = true;
            else
                break;
        }
        for (int i = 0; i < n; ++i) {
            if (s2[i] == s3[i])
                dp[0][i + 1] = true;
            else
                break;
        }

        for (int i = 2; i <= s3.size(); ++i) {
            int up = min(i, m);
            for (int j = 1; j <= up; ++j) {
                if (j + n < i || i == j)
                    continue;
                if (s3[i - 1] != s1[j - 1] && s3[i - 1] != s2[i - j - 1])
                    dp[j][i - j] = false;
                else if (s3[i - 1] == s1[j - 1] && s3[i - 1] != s2[i - j - 1])
                    dp[j][i - j] = dp[j - 1][i - j];
                else if (s3[i - 1] != s1[j - 1] && s3[i - 1] == s2[i - j - 1])
                    dp[j][i - j] = dp[j][i - j - 1];
                else
                    dp[j][i - j] = dp[j - 1][i - j] || dp[j][i - j - 1];
                if (i == s3.size() && dp[j][i - j])
                    return true;
            }
        }
        return false;
    }
};
#endif //LEETCODE_N97_DP_H
