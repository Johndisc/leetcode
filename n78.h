//
// Created by 58253 on 2022/8/8.
//

#ifndef LEETCODE_N78_H
#define LEETCODE_N78_H
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

    void findRes(vector<int> pre_nums, vector<int> &nums, int begin) {
        res.push_back(pre_nums);
        if (begin == nums.size())
            return;
        for (int i = begin; i < nums.size(); ++i) {
            vector<int> next_num = pre_nums;
            next_num.push_back(nums[i]);
            findRes(next_num, nums, i + 1);
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> first;
        findRes(first, nums, 0);
        return res;
    }
};
#endif //LEETCODE_N78_H
