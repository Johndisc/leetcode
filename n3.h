//
// Created by 58253 on 2022/6/10.
//

#ifndef LEETCODE_LONGEST_SUBSTRING_H
#define LEETCODE_LONGEST_SUBSTRING_H

#include <cstring>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int left, right, olen, elen, maxlen = 0, mleft;
        for (int i = 0; i < s.size(); ++i) {
            olen = 1;
            left = i - 1;
            right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                olen += 2;
                left--;
                right++;
            }
            if (olen > maxlen) {
                maxlen = olen;
                mleft = left + 1;
            }
            elen = 0;
            left = i;
            right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                elen += 2;
                left--;
                right++;
            }
            if (elen > maxlen) {
                maxlen = elen;
                mleft = left + 1;
            }
        }
        return s.substr(mleft, maxlen);
    }
};

#endif //LEETCODE_LONGEST_SUBSTRING_H
