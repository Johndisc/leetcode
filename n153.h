//
// Created by 58253 on 2023/1/17.
//

#ifndef LEETCODE_N153_H
#define LEETCODE_N153_H
#include "global.h"

class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0, e = nums.size() - 1, mid;
        while (s <= e) {
            if (s == e || nums[s] < nums[e])
                break;
            mid = (s + e) / 2;
            if (mid > 0 && nums[mid] < nums[mid - 1])
                return nums[mid];
            if (nums[mid] < nums[s])
                e = mid - 1;
            else
                s = mid + 1;
        }
        return nums[s];
    }
};
#endif //LEETCODE_N153_H
