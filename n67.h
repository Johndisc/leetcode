//
// Created by 58253 on 2022/8/17.
//

#ifndef LEETCODE_N67_H
#define LEETCODE_N67_H

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
    string addBinary(string a, string b) {
        if (a.size() > b.size())
            b = string(a.size() - b.size(), '0') + b;
        else
            a = string(b.size() - a.size(), '0') + a;
        string res(a.size() + 1, '0');
        int add_last = 0;
        for (int i = a.size() - 1; i >= 0; --i) {
            int sum = a[i] - '0' + b[i] - '0' + add_last;
            res[i + 1] = sum % 2 + '0';
            add_last = sum / 2;
        }
        res[0] = add_last + '0';
        if (sum[0] == '0')
            return res.substr(1);
        else
            return res;
    }
};
#endif //LEETCODE_N67_H
