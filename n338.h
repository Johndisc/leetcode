//
// Created by CGCL on 2023/2/28.
//

#ifndef LEETCODE_N338_H
#define LEETCODE_N338_H
#include "global.h"

class Solution {
public:
	vector<int> countBits(int n) {
		vector<int> dp(n + 1, 0);
		dp[0] = 0;
		for (int i = 1; i <= n; ++i) {
			dp[i] = i % 2 + dp[i >> 1];
		}
		return dp;
	}
};
#endif //LEETCODE_N338_H
