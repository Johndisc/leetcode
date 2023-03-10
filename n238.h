//
// Created by 58253 on 2023/3/5.
//

#ifndef LEETCODE_N238_H
#define LEETCODE_N238_H
#include "global.h"

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int left = 1, r = 1;
        vector<int> right(nums.size());
        vector<int> res(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--) {
            right[i] = r;
            r *= nums[i];
        }
        for (int i = 0 ; i < nums.size() ; i++) {
            res[i] = left * right[i];
            left *= nums[i];
        }
        return res;
    }
};
#endif //LEETCODE_N238_H
