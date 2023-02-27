//
// Created by CGCL on 2023/2/27.
//

#ifndef LEETCODE_N279_TODO_DP_H
#define LEETCODE_N279_TODO_DP_H
#include "global.h"

class Solution {
public:
	int minNum(vector<int> &dp, int n) {
		if (dp[n] != INT_MAX)
			return dp[n];
		for (int i = 1; i < n; ++i) {
			dp[n] = min(dp[n], minNum(dp, i) + minNum(dp, n - i));
		}
		return dp[n];
	}
	
	int numSquares(int n) {
		vector<int> dp(n + 1, INT_MAX);
		for (int i = 0; i <= 100; ++i) {
			if (i * i <= n)
				dp[i * i] = 1;
			else
				break;
		}
		return minNum(dp, n);
	}
};
#endif //LEETCODE_N279_TODO_DP_H
