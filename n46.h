//
// Created by 58253 on 2022/7/4.
//

#ifndef LEETCODE_N46_H
#define LEETCODE_N46_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    void fillvec(vector<int> &record, vector<int> &nums, vector<bool> &active) {
        if (record.size() == nums.size()) {
            res.push_back(record);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (active[i]) {
                record.push_back(nums[i]);
                active[i] = false;
                fillvec(record, nums, active);
                active[i] = true;
                record.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> record;
        vector<bool> active(nums.size(), true);
        fillvec(record, nums, active);
        return res;
    }
};
#endif //LEETCODE_N46_H
