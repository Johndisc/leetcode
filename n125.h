//
// Created by 58253 on 2022/8/19.
//

#ifndef LEETCODE_N125_H
#define LEETCODE_N125_H
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
    bool isPalindrome(string s) {
        int sp = 0, ep = s.size() - 1;
        while (sp <= ep) {
            if (!isalpha(s[sp]) && !isdigit(s[sp]))
                sp++;
            else if (!isalpha(s[ep]) && !isdigit(s[ep]))
                ep--;
            else
            {
                if (s[sp] >= 'A' && s[sp] <= 'Z')
                    s[sp] -= 'A' - 'a';
                if (s[ep] >= 'A' && s[ep] <= 'Z')
                    s[ep] -= 'A' - 'a';
                if (s[sp] != s[ep])
                    return false;
                sp++;
                ep--;
            }
        }
        return true;
    }
};
#endif //LEETCODE_N125_H
