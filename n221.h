//
// Created by CGCL on 2023/2/27.
//

#ifndef LEETCODE_N221_H
#define LEETCODE_N221_H
#include "global.h"

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int m = matrix.size();
		int n = matrix[0].size();
		int dp[m][n];
		int rowone[m][n], colone[m][n];
		int res = 0;
		
		for (int i = 0; i < m; ++i) {
			rowone[i][0] = matrix[i][0] - '0';
			dp[i][0] = matrix[i][0] - '0';
		}
		for (int i = 0; i < n; ++i) {
			colone[0][i] = matrix[0][i] - '0';
			dp[0][i] = matrix[0][i] - '0';
		}
		
		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				rowone[i][j] = matrix[i][j] == '0' ? 0 : rowone[i][j - 1] + 1;
				colone[i][j] = matrix[i][j] == '0' ? 0 : colone[i - 1][j] + 1;
			}
		}
		
		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				if (matrix[i][j] == '0')
					dp[i][j] = 0;
				else {
					dp[i][j] = min(dp[i - 1][j - 1] + 1, rowone[i][j]);
					dp[i][j] = min(dp[i][j], colone[i][j]);
				}
			}
		}
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				res = max(res, dp[i][j]);
			}
		}
		return res * res;
	}
};
#endif //LEETCODE_N221_H
