//
// Created by 58253 on 2022/8/17.
//

#ifndef LEETCODE_N91_H
#define LEETCODE_N91_H
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
    int numDecodings(string s) {
        if (s[0] == '0')
            return 0;
        vector<int> dp(s.size() + 1, 0);
        dp[1] = 1;
        dp[0] = 1;
        for (int i = 2; i < s.size() + 1; ++i) {
            if (s[i - 1] != '0')
                dp[i] = dp[i - 1];
            if (s[i - 2] != '0') {
                int num = stoi(s.substr(i - 2, 2));
                if (num <= 26)
                    dp[i] += dp[i - 2];
            }
        }
        return dp[s.size()];
    }
};
#endif //LEETCODE_N91_H
