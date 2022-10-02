//
// Created by 58253 on 2022/8/19.
//

#ifndef LEETCODE_N131_H
#define LEETCODE_N131_H
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
    vector<vector<string>> res;

    void findRes(string &s, int start, vector<string> rec, vector<vector<bool>> &dp) {
        if (start == s.size()) {
            res.push_back(rec);
            return;
        }
        for (int i = 1; i <= s.size() - start; ++i) {
            if (dp[start][i] || isRec(s.substr(start, i))) {
                dp[start][i] = true;
                rec.push_back(s.substr(start, i));
                findRes(s, start + i, rec, dp);
                rec.pop_back();
            }
        }
    }

    bool isRec(string s) {
        int sp = 0, ep = s.size() - 1;
        while (sp < ep) {
            if (s[sp] != s[ep])
                return false;
            sp++;
            ep--;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(s.size() + 1, false));
        findRes(s, 0, vector<string>(), dp);
        return res;
    }
};
#endif //LEETCODE_N131_H
