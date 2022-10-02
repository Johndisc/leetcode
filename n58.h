//
// Created by 58253 on 2022/8/17.
//

#ifndef LEETCODE_N58_H
#define LEETCODE_N58_H

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
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        while (s[i] == ' ')
            i--;
        int cnt = 0;
        while (i >= 0 && s[i] != ' ') {
            i--;
            cnt++;
        }
        return cnt;
    }
};
#endif //LEETCODE_N58_H
