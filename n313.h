//
// Created by CGCL on 2023/2/28.
//

#ifndef LEETCODE_N313_H
#define LEETCODE_N313_H
#include "global.h"

class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		vector<int> pointer(primes.size(), 0);
		long long dp[n];
		dp[0] = 1;
		for (int i = 1; i < n; ++i) {
			dp[i] = INT_MAX;
			for (int j = 0; j < primes.size(); ++j) {
				dp[i] = min(dp[i], dp[pointer[j]] * primes[j]);
			}
			for (int j = 0; j < primes.size(); ++j) {
				if (dp[i] == dp[pointer[j]] * primes[j])
					pointer[j]++;
			}
		}
		return dp[n - 1];
	}
};
#endif //LEETCODE_N313_H
