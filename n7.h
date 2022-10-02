//
// Created by 58253 on 2022/6/10.
//
//21.05 - 21.27
#ifndef LEETCODE_INT_REVERSE_H
#define LEETCODE_INT_REVERSE_H

#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x==-2147483648)
            return 0;
        bool ism = x < 0;
        string s = to_string(abs(x)), ns = s;
        for (int i = 0; i < s.size(); ++i) {
            ns[i] = s[s.size() - i - 1];
        }
        if (ns.size() == 10 && ns > to_string(INT_MAX))
            return 0;
        return ism ? (-1) * stoi(ns) : stoi(ns);
    }
};

#endif //LEETCODE_INT_REVERSE_H
