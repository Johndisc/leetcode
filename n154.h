//
// Created by 58253 on 2023/1/18.
//

#ifndef LEETCODE_N154_H
#define LEETCODE_N154_H
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
            else if (nums[mid] > nums[e])
                s = mid + 1;
            else {
                s++;
                e--;
            }
        }
        return nums[s];
    }
};
#endif //LEETCODE_N154_H
