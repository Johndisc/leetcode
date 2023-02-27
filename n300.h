//
// Created by CGCL on 2023/2/27.
//

#ifndef LEETCODE_N300_H
#define LEETCODE_N300_H
#include "global.h"

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int maxlen = 0;
		vector<int> dp(nums.size(), 1);
		for (int i = 1; i < nums.size(); ++i) {
			for (int j = i - 1; j >= 0; --j) {
				if (nums[j] < nums[i])
					dp[i] = max(dp[i], dp[j] + 1);
			}
			maxlen = max(maxlen, dp[i]);
		}
		for (auto item:dp) {
			printf("%d ", item);
		}
		return maxlen;
	}
};
#endif //LEETCODE_N300_H
