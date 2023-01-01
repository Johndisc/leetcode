//
// Created by 58253 on 2023/1/1.
//

#ifndef LEETCODE_N89_H
#define LEETCODE_N89_H
#include "global.h"

class Solution {
public:
    vector<int> grayCode(int n) {
        int x = 0;
        vector<int> res, mid;
        res.push_back(0);
        res.push_back(1);
        for (int i = 1; i < n; ++i) {
            x = pow(2, i);
            for (auto it = res.rbegin(); it != res.rend(); it++)
                mid.push_back(x + (*it));
            res.insert(res.end(), mid.begin(), mid.end());
            mid.clear();
        }
        return res;
    }
};
#endif //LEETCODE_N89_H
