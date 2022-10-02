//
// Created by 58253 on 2022/8/17.
//

#ifndef LEETCODE_N87_TODO_DP_H
#define LEETCODE_N87_TODO_DP_H
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
    bool isScramble(string s1, string s2) {
        int m = s1.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(m + 1, false));
        for (int i = 0; i < m; ++i) {
            dp[i][i] = (s1[i] == s2[i]);
        }

        for (int j = 1; j < m; ++j) {
            for (int i = 0; i < m - j; ++i) {
                for (int k = 0; k < j; ++k) {
                    if (dp[i][i + k] && dp[i + k + 1][i + j]) {
                        dp[i][i + j] = true;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[0][m - 1];
    }
};
#endif //LEETCODE_N87_TODO_DP_H
