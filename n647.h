//
// Created by CGCL on 2023/3/6.
//

#ifndef LEETCODE_N647_H
#define LEETCODE_N647_H
#include "global.h"

class Solution {
public:
	int countSubstrings(string s) {
		vector <vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
		int res = s.size();
		for (int i = 0; i < s.size() - 1; ++i) {
			dp[i][i] = true;
			dp[i][i + 1] = s[i] == s[i + 1];
			if (dp[i][i + 1])
				res++;
		}
		dp[s.size() - 1][s.size() - 1] = true;
		for (int i = 2; i < s.size(); ++i) {
			for (int j = 0; j < s.size() - i; ++j) {
				dp[j][j + i] = dp[j + 1][j + i - 1] && (s[j] == s[j + i]);
				if (dp[j][j + i])
					res++;
			}
		}
		return res;
	}
};
#endif //LEETCODE_N647_H
