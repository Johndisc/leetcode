//
// Created by 58253 on 2023/1/14.
//

#ifndef LEETCODE_N136_H
#define LEETCODE_N136_H
#include "global.h"

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (auto e: nums) ret ^= e;
        return ret;
    }
};
#endif //LEETCODE_N136_H
