//
// Created by 58253 on 2023/1/17.
//

#ifndef LEETCODE_N152_H
#define LEETCODE_N152_H
#include "global.h"

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> dpmax(nums.size(), INT_MIN), dpmin(nums.size(), INT_MAX);
        int maxmul = nums[0];
        dpmax[0] = dpmin[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                dpmax[i] = max(dpmax[i - 1] * nums[i], nums[i]);
                dpmin[i] = min(dpmin[i - 1] * nums[i], nums[i]);
            }
            else {
                dpmax[i] = max(dpmin[i - 1] * nums[i], nums[i]);
                dpmin[i] = min(dpmax[i - 1] * nums[i], nums[i]);
            }
            maxmul = max(maxmul, dpmax[i]);
        }
        return maxmul;
    }
};
#endif //LEETCODE_N152_H
