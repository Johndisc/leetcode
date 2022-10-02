//
// Created by 58253 on 2022/8/8.
//

#ifndef LEETCODE_N9_H
#define LEETCODE_N9_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string s1 = s;
        reverse(s1.begin(), s1.end());
        if (s == s1)
            return true;
        else
            return false;
    }
};
#endif //LEETCODE_N9_H
