//
// Created by CGCL on 2023/3/6.
//

#ifndef LEETCODE_N560_H
#define LEETCODE_N560_H
#include "global.h"

class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		int left = 0, right = 1;
		int total = nums[1];
		int res = 0;
		while (right < nums.size() || total >= k) {
			if (total == k) {
				res++;
				total -= nums[left];
				left++;
			}
			else if (total > k) {
				total -= nums[left];
				left++;
			}
			else {
				total += nums[right];
				right++;
			}
			if (left > right)
			
		}
		return res;
	}
};
#endif //LEETCODE_N560_H
