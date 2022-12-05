//
// Created by 58253 on 2022/12/5.
//

#ifndef LEETCODE_N29_H
#define LEETCODE_N29_H

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
    int divide(int dividend, int divisor) {
        long long ldend = abs((long long)dividend), ldsor = abs((long)divisor), mid = 0;
        if (ldend < ldsor)
            return 0;
        bool is_minus;
        if (divisor < 0 && dividend < 0 || divisor > 0 && dividend > 0)
            is_minus = false;
        else
            is_minus = true;
        string res;
        string sdend = to_string(ldend), sdsor = to_string(ldsor);
        int pos = sdsor.size() - 1;
        if (pos > 0)
            mid = stol(sdend.substr(0, pos));
        while (pos < sdend.size()) {
            mid = stol(to_string(mid) + sdend[pos]);
            pos++;
            int k = 0;
            while (mid >= ldsor) {
                k++;
                mid -= ldsor;
            }
            res += to_string(k);
        }
        if (is_minus)
            res.insert(0, "-");
        if (stoll(res) > INT_MAX)
            return INT_MAX;
        return stoi(res);
    }
};
#endif //LEETCODE_N29_H
