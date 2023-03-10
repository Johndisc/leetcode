//
// Created by CGCL on 2023/3/3.
//

#ifndef LEETCODE_N240_H
#define LEETCODE_N240_H
#include "global.h"

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size(), n = matrix[0].size();
		int s, e, midcol;
		for (int i = 0; i < m; ++i) {
			s = 0;
			e = n - 1;
			while (s <= e) {
				midcol = (s + e) / 2;
				if (matrix[i][midcol] == target)
					return true;
				if (matrix[i][midcol] > target)
					e = midcol - 1;
				else
					s = midcol + 1;
			}
		}
		
		return false;
	}
};
#endif //LEETCODE_N240_H
