//
// Created by 58253 on 2022/9/12.
//

#ifndef LEETCODE_N166_H
#define LEETCODE_N166_H
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
    string fractionToDecimal(int numerator, int denominator) {
        unordered_map<long long, long long > tail;
        long long numerator1 = numerator, denominator1 = denominator;
        if (denominator == -2147483648)
            denominator1 = -2147483648;
        long pos = 0;
        string ans;
        if ((numerator1 < 0 && denominator1 > 0) || (numerator1 > 0 && denominator1 < 0)) {
            ans = "-";
        }
        numerator1 = abs(numerator1);
        denominator1 = abs(denominator1);
        ans += to_string(numerator1 / denominator1);
        numerator1 = numerator1 % denominator1;
        if (numerator1 == 0)
            return ans;
        ans += ".";
        string latter;
        numerator1 *= 10;
        while (true) {
            if (numerator1 < denominator1) {
                if (tail.find(numerator1) != tail.end() && latter[tail[numerator1]] == '0') {
                    latter.insert(tail[numerator1], 1, '(');
                    latter += ")";
                    break;
                }
                tail[numerator1] = pos;
                numerator1 *= 10;
                latter += "0";
                pos++;
                continue;
            }
            latter += to_string(numerator1 / denominator1);
            numerator1 = numerator1 % denominator1;
            if (numerator1 == 0)
                break;
            if (tail.find(numerator1) != tail.end() && latter[tail[numerator1]] == latter[latter.size() - 1]) {
                latter.insert(tail[numerator1], 1, '(');
                latter.erase(latter.size() - 1, 1);
                latter += ")";
                break;
            }
            tail[numerator1] = pos;
            numerator1 *= 10;
            pos++;
        }
        return ans + latter;
    }
};
#endif //LEETCODE_N166_H
