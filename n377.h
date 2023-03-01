//
// Created by CGCL on 2023/3/1.
//

#ifndef LEETCODE_N377_H
#define LEETCODE_N377_H
#include "global.h"

class Solution {
public:
	int searchNum(vector<int> &dp, vector<int> &nums, int target) {
		if (dp[target] != -1)
			return dp[target];
		for (auto j: nums) {
			if (target >= j)
				dp[target] += searchNum(dp, nums, target - j);
		}
		dp[target]++;
		return dp[target];
	}
	
	int combinationSum4(vector<int>& nums, int target) {
		vector<int> dp(target + 1, -1);
		dp[0] = 1;
		return searchNum(dp, nums, target);
	}
};
#endif //LEETCODE_N377_H
