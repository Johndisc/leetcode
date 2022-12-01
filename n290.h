//
// Created by 58253 on 2022/10/8.
//

#ifndef LEETCODE_N290_H
#define LEETCODE_N290_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> table;
        unordered_set<string> set;
        for (char &c: pattern) {
            if (s.empty())
                return false;
            int pos = s.find(' ');
            string sub;
            if (pos == -1) {
                sub = s;
                s.clear();
            } else {
                sub = s.substr(0, pos);
                s = s.substr(pos + 1);
            }
            if (!table.count(c) && !set.count(sub)) {
                set.insert(sub);
                table[c] = sub;
            } else if (sub != table[c])
                return false;
        }
        if (s.empty())
            return true;
        else
            return false;
    }
};
#endif //LEETCODE_N290_H
