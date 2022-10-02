//
// Created by 58253 on 2022/8/9.
//

#ifndef LEETCODE_N17_H
#define LEETCODE_N17_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> index = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    void findRes(string digits, string s, int pos) {
        if (pos >= digits.size()) {
            res.push_back(s);
            return;
        }
        int num = digits[pos] - '0';
        for (char c: index[num]) {
            s[pos] = c;
            findRes(digits, s, pos + 1);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return res;
        string s = digits;
        findRes(digits, s, 0);
        return res;
    }
};
#endif //LEETCODE_N17_H
