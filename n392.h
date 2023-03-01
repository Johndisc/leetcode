//
// Created by CGCL on 2023/3/1.
//

#ifndef LEETCODE_N392_H
#define LEETCODE_N392_H
#include "global.h"

class Solution {
public:
	bool isSubsequence(string s, string t) {
		int m = s.size(), n = t.size();
		if (m == 0)
			return true;
		if (n == 0 || n < m)
			return false;
		vector <vector<bool>> dp(m, vector<bool>(n, false));
		bool state = false;
		for (int i = 0; i < n; ++i) {
			if (t[i] == s[0])
				state = true;
			dp[0][i] = state;
		}
		for (int i = 1; i < m; ++i) {
			for (int j = i; j < n; ++j) {
				if (s[i] == t[j])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = dp[i][j - 1];
			}
		}
		return dp[m - 1][n - 1];
	}
};
#endif //LEETCODE_N392_H
