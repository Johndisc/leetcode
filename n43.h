//
// Created by 58253 on 2022/8/16.
//

#ifndef LEETCODE_N43_H
#define LEETCODE_N43_H
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
    string multiplySingle(string &num, char c) {
        int i = c - '0';
        int add_one = 0;
        string res(num.size() + 1, '0');
        for (int j = num.size() - 1; j >= 0; --j) {
            int mul = i * (num[j] - '0') + add_one;
            res[j + 1] = mul % 10 + '0';
            add_one = mul / 10;
        }
        res[0] = add_one + '0';
        if (add_one == 0)
            return res.substr(1);
        else
            return res;
    }

    string addTwoString(string num1, string num2) {
        if (num1.size() > num2.size())
            num2 = string(num1.size() - num2.size(), '0') + num2;
        else
            num1 = string(num2.size() - num1.size(), '0') + num1;
        string res(num1.size() + 1, '0');
        int add_one = 0;
        for (int i = num1.size() - 1; i >= 0; --i) {
            int n = num1[i] - '0' + num2[i] - '0' + add_one;
            res[i + 1] = n % 10 + '0';
            add_one = n / 10;
        }
        res[0] = add_one + '0';
        if (add_one == 0)
            return res.substr(1);
        else
            return res;
    }

    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        string res;
        for (int i = num2.size() - 1; i >= 0; --i) {
            string mul = multiplySingle(num1, num2[i]) + string(num2.size() - 1 - i, '0');
            res = addTwoString(res, mul);
        }
        return res;
    }
};
#endif //LEETCODE_N43_H
