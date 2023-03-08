//
// Created by CGCL on 2023/3/6.
//

#ifndef LEETCODE_N283_H
#define LEETCODE_N283_H
#include "global.h"

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int p1 = 0, p2, p3;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] != 0) {
				swap(nums[i], nums[p1]);
				p1++;
			}
		}
	}
};
#endif //LEETCODE_N283_H
