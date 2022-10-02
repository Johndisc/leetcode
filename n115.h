//
// Created by 58253 on 2022/8/18.
//

#ifndef LEETCODE_N115_H
#define LEETCODE_N115_H
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
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        if (m < n)
            return 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m + 1; ++i)
            dp[i][0] = 1;
        for (int j = 1; j < n + 1; ++j)
            dp[0][j] = 0;

        for (int i = 1; i < m + 1; ++i) {
            for (int j = i - (m - n) > 1 ? i - (m - n) : 1; j < n + 1; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (s[i - 1] == t[j - 1])
                    dp[i][j] += dp[i - 1][j - 1];
            }
        }
        return dp[m][n];
    }
};
#endif //LEETCODE_N115_H
