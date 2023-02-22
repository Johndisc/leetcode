//
// Created by CGCL on 2023/2/22.
//

#ifndef LEETCODE_N209_H
#define LEETCODE_N209_H
#include "global.h"

class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		int s, e, minlen = INT_MAX, len = 0, sum = 0;
		s = e = 0;
		while (e != nums.size()) {
			sum += nums[e];
			len++;
			if (sum >= target) {
				while (sum >= target) {
					sum -= nums[s];
					s++;
					len--;
				}
				minlen = min(minlen, len + 1);
			}
			e++;
		}
		return minlen == INT_MAX ? 0 : minlen;
	}
};
#endif //LEETCODE_N209_H