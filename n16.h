//
// Created by 58253 on 2022/6/12.
//

#ifndef LEETCODE_N16_H
#define LEETCODE_N16_H
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findk(vector<int> &nums, int target, int start) {
        int s = start, e = nums.size() - 1;
        if (nums[s] >= target)
            return nums[s];
        if(nums[e] <= target)
            return nums[e];
        while (s < e) {
            if (e - s == 1)
                return target - nums[s] < nums[e] - target ? nums[s] : nums[e];
            int mid = (s + e) / 2;
            if (nums[mid] == target)
                return target;
            else if (nums[mid] > target)
                e = mid;
            else
                s = mid;
        }
        return s;
    }

    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int delta = INT_MAX, mx = 0;
        for (int i = 0; i < nums.size() - 2; ++i) {
            for (int j = i + 1; j < nums.size() - 1; ++j) {
                int k = target - nums[i] - nums[j];
                k = findk(nums, k, j + 1);
                if (abs(nums[i] + nums[j] + k - target) < delta) {
                    mx = nums[i] + nums[j] + k;
                    delta = abs(nums[i] + nums[j] + k - target);
                    if (delta == 0)
                        return mx;
                }
            }
        }
        return mx;
    }
};
#endif //LEETCODE_N16_H
