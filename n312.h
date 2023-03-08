//
// Created by CGCL on 2023/3/6.
//

#ifndef LEETCODE_N312_H
#define LEETCODE_N312_H
#include "global.h"

class Solution {
public:
	int maxCoins(vector<int>& nums) {
		nums.insert(nums.begin(), 1);
		nums.push_back(1);
		vector <vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, 0));
		for (int i = 0; i < nums.size() - 1; ++i)
			dp[i][i + 1] = 0;
		for (int i = 2; i < nums.size(); ++i) {
			for (int j = 0; j < nums.size() - i; ++j) {
				for (int k = j + 1; k < j + i - 1; ++k) {
					dp[j][j + i] = max(dp[j][j + i], dp[j][k] + dp[k][j + i] + nums[k] * nums[j] * nums[j + i]);
				}
			}
		}
		return dp[0][nums.size() - 1];
	}
};
#endif //LEETCODE_N312_H
