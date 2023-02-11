//
// Created by CGCL on 2023/2/11.
//

#ifndef LEETCODE_N164_H
#define LEETCODE_N164_H
#include "global.h"

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        int maxNum = *max_element(nums.begin(), nums.end());
        int exp = 1, res = 0;
        while (exp <= maxNum) {
            vector<int> cnt(10, 0), temp(nums.size());
            for (int num : nums)
                cnt[(num / exp) % 10]++;
            for (int i = 1; i < 10; ++i)
                cnt[i] += cnt[i - 1];
            for (int i = nums.size() - 1; i >= 0; --i)
                temp[--cnt[(nums[i] / exp) % 10]] = nums[i];
            nums.assign(temp.begin(), temp.end());
            exp *= 10;
        }
        for (int i = 1; i < nums.size(); ++i)
            res = max(res, nums[i] - nums[i - 1]);
        return res;
    }
};
#endif //LEETCODE_N164_H
