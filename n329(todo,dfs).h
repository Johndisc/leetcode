//
// Created by CGCL on 2023/2/28.
//

#ifndef LEETCODE_N329_TODO_DFS_H
#define LEETCODE_N329_TODO_DFS_H
#include "global.h"

class Solution {
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		int maxlen = 0;
		//以ij结尾的最长递增序列
		vector <vector<int>> inc(m, vector<int>(n, 1));
		//以ij结尾的最长递减序列
		vector <vector<int>> dec(m, vector<int>(n, 1));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i > 0) {
					if (matrix[i][j] > matrix[i - 1][j])
						inc[i][j] = max(inc[i][j], inc[i - 1][j] + 1);
					else if (matrix[i][j] < matrix[i - 1][j])
						dec[i][j] = max(dec[i][j], dec[i - 1][j] + 1);
				}
				if (j > 0) {
					if (matrix[i][j] > matrix[i][j - 1])
						inc[i][j] = max(inc[i][j], inc[i][j - 1] + 1);
					else if (matrix[i][j] < matrix[i][j - 1])
						dec[i][j] = max(dec[i][j], dec[i][j - 1] + 1);
				}
				maxlen = max(maxlen, inc[i][j]);
				maxlen = max(maxlen, dec[i][j]);
			}
			for (int j = 0; j < n; ++j) {
				if (i > 0) {
					if (matrix[i][j] > matrix[i - 1][j])
						inc[i][j] = max(inc[i][j], inc[i - 1][j] + 1);
					else if (matrix[i][j] < matrix[i - 1][j])
						dec[i][j] = max(dec[i][j], dec[i - 1][j] + 1);
				}
				if (j > 0) {
					if (matrix[i][j] > matrix[i][j - 1])
						inc[i][j] = max(inc[i][j], inc[i][j - 1] + 1);
					else if (matrix[i][j] < matrix[i][j - 1])
						dec[i][j] = max(dec[i][j], dec[i][j - 1] + 1);
				}
				maxlen = max(maxlen, inc[i][j]);
				maxlen = max(maxlen, dec[i][j]);
			}
		}
		
		return maxlen;
	}
};

7 8 9
9 7 6
7 2 3

#endif //LEETCODE_N329_TODO_DFS_H
