//
// Created by 58253 on 2022/8/10.
//

#ifndef LEETCODE_N22_H
#define LEETCODE_N22_H

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
    vector<string> res;
    void findRes(string s, int n, int cnt) {
        if (cnt < 0)
            return;
        if (n == s.size()) {
            if (cnt == 0)
                res.push_back(s);
            return;
        }
        if (cnt < s.size() / 2) {
            s[n] = '(';
            findRes(s, n + 1, cnt + 1);
        }
        if (cnt > 0) {
            s[n] = ')';
            findRes(s, n + 1, cnt - 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        string s(n * 2, '.');
        findRes(s, 0, 0);
        return res;
    }
};
#endif //LEETCODE_N22_H
