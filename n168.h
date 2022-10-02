//
// Created by 58253 on 2022/9/13.
//

#ifndef LEETCODE_N168_H
#define LEETCODE_N168_H
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
    string convertToTitle(int columnNumber) {
        string ans;
        while (columnNumber != 0) {
            ans.append(1, 'A' + (columnNumber - 1) % 26);
            columnNumber = (columnNumber - 1) / 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
#endif //LEETCODE_N168_H
