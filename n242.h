//
// Created by 58253 on 2022/10/8.
//

#ifndef LEETCODE_N242_H
#define LEETCODE_N242_H

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
    bool isAnagram(string s, string t) {
        unordered_map<char, int> table;
        for (char &c: s)
            table[c]++;
        for (char &c: t) {
            table[c]--;
            if (table[c] == 0)
                table.erase(c);
        }
        if (table.empty())
            return true;
        else
            return false;
    }
};
#endif //LEETCODE_N242_H
