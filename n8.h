//
// Created by 58253 on 2022/6/10.
//
//21.28 - 22.07
#ifndef LEETCODE_ATOI_H
#define LEETCODE_ATOI_H

#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        bool ism = false;
        long sum = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ')
                continue;
            if (s[i] == '+')
            {
                i++;
                while (i < s.size()) {
                    if (s[i]<'0'||s[i]>'9')
                        return sum;
                    sum = sum * 10 + s[i] - '0';
                    if (sum > INT_MAX)
                        return INT_MAX;
                    i++;
                }
                return sum;
            }
            if (s[i] == '-') {
                ism = true;
                i++;
                while (i < s.size()) {
                    if (s[i]<'0'||s[i]>'9')
                        return -1 * sum;
                    sum = sum * 10 + s[i] - '0';
                    if (sum > INT_MAX)
                        return -INT_MAX - 1;
                    i++;
                }
                return -1 * sum;
            }
            if (s[i]<'0'||s[i]>'9')
                return sum;
            while (i < s.size()) {
                if (s[i]<'0'||s[i]>'9')
                    return sum;
                sum = sum * 10 + s[i] - '0';
                if (sum > INT_MAX)
                    return INT_MAX;
                i++;
            }
        }
        return static_cast<int>(ism ? -1 * sum : sum);
    }
};

#endif //LEETCODE_ATOI_H
