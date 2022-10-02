//
// Created by 58253 on 2022/7/12.
//

#ifndef LEETCODE_N66_H
#define LEETCODE_N66_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits[0] == 0)
            return vector<int>{1};
        vector<int> res = digits;
        for (auto it = res.end() - 1; it >= res.begin(); it--) {
            *it = (*it + 1) % 10;
            if (*it != 0)
                break;
        }
        if (res[0] == 0)
            res.insert(res.begin(), 1);
        return res;
    }
};
#endif //LEETCODE_N66_H
