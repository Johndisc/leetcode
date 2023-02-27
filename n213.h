//
// Created by CGCL on 2023/2/27.
//

#ifndef LEETCODE_N213_H
#define LEETCODE_N213_H
#include "global.h"

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 1)
			return nums[0];
		vector<int> dp(nums);
		int money = 0;
		dp[0] = 0;
		dp[1] = nums[1];
		for (int i = 2; i < dp.size(); ++i) {
			dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
		}
		money = dp[dp.size() - 1];
		
		dp[0] = nums[0];
		dp[1] = dp[0];
		for (int i = 2; i < dp.size() - 1; ++i) {
			dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
		}
		return max(money, dp[dp.size() - 2]);
	}
};
#endif //LEETCODE_N213_H
