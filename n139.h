//
// Created by 58253 on 2022/8/21.
//

#ifndef LEETCODE_N139_H
#define LEETCODE_N139_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <map>

using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for (auto &item: wordDict)
            dict.insert(item);
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int i = 1; i <= s.size(); ++i) {
            for (auto &item:wordDict) {
                if (i >= item.size() && s.substr(i - item.size(), item.size()) == item) {
                    dp[i] = dp[i] | dp[i - item.size()];
                }
            }
//            cout << dp[i] << " ";
        }
//        cout << endl;
        return dp[s.size()];
    }
};
#endif //LEETCODE_N139_H
