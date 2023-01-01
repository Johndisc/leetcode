//
// Created by 58253 on 2023/1/1.
//

#ifndef LEETCODE_N90_H
#define LEETCODE_N90_H
#include "global.h"

class Solution {
public:
    vector<vector<int>> res;

    void findRes(vector<int> mid, vector<int> &nums, int pos) {
        if (pos == nums.size())
            return;
        for (int i = pos; i < nums.size(); ++i) {
            if (i > pos && nums[i] == nums[i - 1])
                continue;
            mid.push_back(nums[i]);
            res.push_back(mid);
            findRes(mid, nums, i + 1);
            mid.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> mid;
        res.push_back(mid);
        findRes(mid, nums, 0);
        return res;
    }
};
#endif //LEETCODE_N90_H
