//
// Created by 58253 on 2022/9/13.
//

#ifndef LEETCODE_N171_H
#define LEETCODE_N171_H
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
    int titleToNumber(string columnTitle) {
        int ans = 0;
        for (char &c: columnTitle) {
            ans = ans * 26 + (c - 'A') + 1;
        }
        return ans;
    }
};
#endif //LEETCODE_N171_H
