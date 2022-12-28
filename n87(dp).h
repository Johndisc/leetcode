//
// Created by 58253 on 2022/8/17.
//

#ifndef LEETCODE_N87_DP_H
#define LEETCODE_N87_DP_H
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
        int dp[m][m + 1][m];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                dp[i][1][j] = s1[i] == s2[j];
            }
        }
        for (int i = 2; i < m + 1; ++i) {   //长度
            for (int j = 0; j < m - i + 1; ++j) {   //原始位置
                for (int k = 0; k < m - i + 1; ++k) {   //放置位置
                    dp[j][i][k] = false;
                    for (int l = 1; l < i; ++l) {   //分割位置
                        if (dp[j][l][k] && dp[j + l][i - l][k + l]) {
                            dp[j][i][k] = true;
                            break;
                        }
                        if (dp[j][l][k + i - l] && dp[j + l][i - l][k]) {
                            dp[j][i][k] = true;
                            break;
                        }
                    }
                }
            }
        }
//        for (int i = 1; i < m + 1; ++i) {   //长度
//            for (int j = 0; j < m - i + 1; ++j) {   //原始位置
//                for (int k = 0; k < m - i + 1; ++k) {   //放置位置
//                    cout << dp[j][i][k] << " ";
//                }
//                cout << endl;
//            }
//            cout << endl;
//        }
        return dp[0][m][0];
    }
};
#endif //LEETCODE_N87_DP_H
