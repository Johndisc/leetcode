//
// Created by 58253 on 2022/8/21.
//

#ifndef LEETCODE_N140_H
#define LEETCODE_N140_H
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
    unordered_set<string> dict;
    vector<string> res;

    void findRes(string s, int start, vector<vector<bool>> &dp, int depth) {
        if (start == s.size()) {
            s.erase(start - 1, 1);
            res.push_back(s);
            return;
        }
        for (int i = 1; i <= s.size() - start; ++i) {
            if (dp[start - depth][i] || dict.find(s.substr(start, i)) != dict.end()) {
                dp[start - depth][i] = true;
                s.insert(start + i, " ");
                findRes(s, start + i + 1, dp, depth + 1);
                s.erase(start + i, 1);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (auto &item: wordDict)
            dict.insert(item);
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(s.size() + 1, false));     //dp[i][j]表示从i开始的j个单词是否再dict中
        findRes(s, 0, dp, 0);
        return res;
    }
};
#endif //LEETCODE_N140_H
