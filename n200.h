//
// Created by CGCL on 2023/2/22.
//

#ifndef LEETCODE_N200_H
#define LEETCODE_N200_H
#include "global.h"

class Solution {
public:
	int m;
	int n;
	void dig(vector <vector<char>> &grid, int i, int j) {
		grid[i][j] = '0';
		if (i > 0 && grid[i - 1][j] == '1')
			dig(grid, i - 1, j);
		if (i < m - 1 && grid[i + 1][j] == '1')
			dig(grid, i + 1, j);
		if (j > 0 && grid[i][j - 1] == '1')
			dig(grid, i, j - 1);
		if (j < n - 1 && grid[i][j + 1] == '1')
			dig(grid, i, j + 1);
	}
	
	int numIslands(vector<vector<char>>& grid) {
		m = grid.size();
		n = grid[0].size();
		int cnt = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == '1') {
					cnt++;
					dig(grid, i, j);
				}
			}
		}
		return cnt;
	}
};
#endif //LEETCODE_N200_H
