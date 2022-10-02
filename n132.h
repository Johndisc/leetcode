//
// Created by 58253 on 2022/8/19.
//

#ifndef LEETCODE_N132_H
#define LEETCODE_N132_H
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
    int minCut(string s) {
        int len = s.size();
        vector<int> dp(len + 1, INT_MAX);
        vector<vector<bool>> is_rec(len + 1, vector<bool>(len + 1, false));

        dp[len - 1] = 0;
        for (int i = len - 1; i >= 0; --i) {
            is_rec[i][0] = true;
            for (int j = 1; j <= len - i; ++j) {
                if (j == 1)
                    is_rec[i][j] = true;
                else
                    is_rec[i][j] = (s[i] == s[i + j - 1]) && is_rec[i + 1][j - 2];
                if (is_rec[i][j]) {
                    is_rec[i][j] = true;
                    if (i + j == len)
                        dp[i] = 0;
                    else
                        dp[i] = min(dp[i], dp[i + j] + 1);
                }
            }
        }
        return dp[0];
    }
};
#endif //LEETCODE_N132_H
