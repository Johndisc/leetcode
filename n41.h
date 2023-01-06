//
// Created by 58253 on 2023/1/6.
//

#ifndef LEETCODE_N41_H
#define LEETCODE_N41_H
#include "global.h"

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            if (nums[i] == i + 1)
                continue;
            if (nums[i] > size)
                nums[i] = -nums[i];
            else if (nums[i] > 0 && nums[i] <= size) {
                int temp = nums[i] - 1;
                if (nums[temp] == temp + 1)
                    nums[i] = -nums[i];
                else {
                    nums[i] = nums[temp];
                    nums[temp] = temp + 1;
                    i--;
                }
            }
        }

        for (int i = 0; i < size; ++i) {
            if (nums[i] <= 0)
                return i + 1;
        }
        return size + 1;
    }
};
#endif //LEETCODE_N41_H
