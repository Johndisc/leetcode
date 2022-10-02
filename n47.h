//
// Created by 58253 on 2022/7/4.
//

#ifndef LEETCODE_N47_H
#define LEETCODE_N47_H
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

    void fillvec(vector<int> &record, vector<int> &nums, int next, int start_pos) {
        if (start_pos >= nums.size())
            return;
        if (next == nums.size() - 1) {
            for (int i = start_pos; i < record.size(); ++i)
                if (record[i] == 20) {
                    record[i] = nums[next];
                    res.push_back(record);
                    record[i] = 20;
                    return;
                }
            return;
        }
        for (int i = start_pos; i < record.size(); ++i) {
            if (record[i] == 20) {
                record[i] = nums[next];
                if (nums[next + 1] == nums[next])
                    fillvec(record, nums, next + 1, i + 1);
                else
                    fillvec(record, nums, next + 1, 0);
                record[i] = 20;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> record(nums.size(), 20);
        sort(nums.begin(), nums.end());
        fillvec(record, nums, 0, 0);
        return res;
    }
};
#endif //LEETCODE_N47_H
