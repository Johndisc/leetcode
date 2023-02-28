//
// Created by CGCL on 2023/2/28.
//

#ifndef LEETCODE_N343_H
#define LEETCODE_N343_H
#include "global.h"

class Solution {
public:
	int integerBreak(int n) {
		vector<int> dp(n + 1, 0);
		dp[0] = 0;
		dp[1] = 1;
		for (int i = 2; i <= n; ++i) {
			for (int j = 1; j < i; ++j) {
				dp[i] = max(j * (i - j), max(dp[i], j * dp[i - j]));
			}
		}
		return dp[n];
	}
};
#endif //LEETCODE_N343_H
