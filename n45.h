//
// Created by 58253 on 2022/7/3.
//

#ifndef LEETCODE_N45_H
#define LEETCODE_N45_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> steps(nums.size());
        steps[steps.size() - 1] = 0;
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] == 0) {
                steps[i] = INT_MAX;
                continue;
            }
            int minnum = steps[i + 1];
            if (i + nums[i] >= nums.size() - 1) {
                steps[i] = 1;
                continue;
            }
            for (int j = 1; j <= nums[i]; ++j) {
                if (j + nums[i + j] <= nums[i]) {
                    minnum = min(minnum, steps[i + j] - 1);
                    j = j + nums[i + j];
                }
                else
                    minnum = min(minnum, steps[i + j]);

            }
            steps[i] = minnum + 1;
        }
        return steps[0];
    }
};
#endif //LEETCODE_N45_H
