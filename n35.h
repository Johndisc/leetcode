//
// Created by 58253 on 2022/7/5.
//

#ifndef LEETCODE_N35_H
#define LEETCODE_N35_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1, mid;
        if (target > nums[e])
            return e + 1;
        if (target <= nums[s])
            return s;
        while (s <= e) {
            mid = (s + e) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[s] < target && nums[s + 1] >= target)
                return s + 1;
            if (nums[mid] < target)
                s = mid;
            else
                e = mid;
        }
        return 0;
    }
};

#endif //LEETCODE_N35_H
