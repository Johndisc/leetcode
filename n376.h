//
// Created by CGCL on 2023/3/1.
//

#ifndef LEETCODE_N376_H
#define LEETCODE_N376_H
#include "global.h"

class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		vector<int> up(nums.size(), 1), down(nums.size(), 1);
		for (int i = 1; i < nums.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				if (nums[j] < nums[i])
					up[i] = max(up[i], down[j] + 1);
				else if (nums[j] > nums[i])
					down[i] = max(down[i], up[j] + 1);
			}
		}
		return max(up[nums.size() - 1], down[nums.size() - 1]);
	}
};
#endif //LEETCODE_N376_H
