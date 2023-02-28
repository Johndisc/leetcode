//
// Created by 58253 on 2023/2/28.
//

#ifndef LEETCODE_N368_H
#define LEETCODE_N368_H
#include "global.h"

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1), last(nums.size(), -1);
        int maxlen = 0, k;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    last[i] = j;
                }
            }
            if (dp[i] > maxlen) {
                maxlen = dp[i];
                k = i;
            }
        }
        vector<int> res;
        while (k != -1) {
            res.push_back(nums[k]);
            k = last[k];
        }
        return res;
    }
};
#endif //LEETCODE_N368_H
