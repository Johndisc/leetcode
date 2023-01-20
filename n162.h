//
// Created by 58253 on 2023/1/20.
//

#ifndef LEETCODE_N162_H
#define LEETCODE_N162_H
#include "global.h"

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        int s = 0, e = nums.size() - 1, mid;
        if (nums[0] > nums[1])
            return 0;
        if (nums[e] > nums[e - 1])
            return e;
        s++;
        e--;
        while (s <= e) {
            if (nums[s] > nums[s - 1] && nums[s] > nums[s + 1])
                return s;
            if (nums[e] > nums[e - 1] && nums[e] > nums[e + 1])
                return e;
            mid = (s + e) / 2;
            printf("%d %d %d\n", s, e, mid);
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;
            else if (nums[mid] < nums[mid - 1])
                e = mid - 1;
            else
                s = mid + 1;
        }
        return s;
    }
};
#endif //LEETCODE_N162_H
