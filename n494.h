//
// Created by CGCL on 2023/3/3.
//

#ifndef LEETCODE_N494_H
#define LEETCODE_N494_H
#include "global.h"

class Solution {
public:
	int dfs(vector<int> &nums, int target, vector <unordered_map<int, int>> &dp, int i) {
		if (i == 0 || dp[i].find(target) != dp[i].end())
			return dp[i][target];
		
		dp[i][target] = dfs(nums, target + nums[i], dp, i - 1) + dfs(nums, target - nums[i], dp, i - 1);
		return dp[i][target];
	}
	
	int findTargetSumWays(vector<int>& nums, int target) {
		vector <unordered_map<int, int>> dp(nums.size());
		dp[0][nums[0]] = 1;
		dp[0][-nums[0]] += 1;
		int res = dfs(nums, target, dp, nums.size() - 1);
		return res;
	}
};
#endif //LEETCODE_N494_H
