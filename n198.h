//
// Created by CGCL on 2023/2/22.
//

#ifndef LEETCODE_N198_H
#define LEETCODE_N198_H
#include "global.h"

class Solution {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();
		int steal[n], notsteal[n];
		steal[0] = nums[0];
		notsteal[0] = 0;
		for (int i = 1; i < n; ++i) {
			steal[i] = notsteal[i - 1] + nums[i];
			notsteal[i] = max(steal[i - 1], notsteal[i - 1]);
		}
		return max(steal[n - 1], notsteal[n - 1]);
	}
};
#endif //LEETCODE_N198_H
