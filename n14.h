//
// Created by 58253 on 2022/8/9.
//

#ifndef LEETCODE_N14_H
#define LEETCODE_N14_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        string res;
        int pos = 0;
        while (pos < strs[0].size()) {
            char c = strs[0][pos];
            for (auto &it: strs) {
                if (pos >= it.size() || it[pos] != c)
                    return res;
            }
            pos++;
            res += c;
        }
        return res;
    }
};
#endif //LEETCODE_N14_H
