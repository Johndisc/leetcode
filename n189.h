//
// Created by CGCL on 2023/2/21.
//

#ifndef LEETCODE_N189_H
#define LEETCODE_N189_H
#include "global.h"

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int size = nums.size();
		k = k % size;
		if (k == 0)
			return;
		for (int i = size - 1; i >= size % k + k; --i) {
			swap(nums[i], nums[i - k]);
		}
		vector<int> temp(nums.begin(), nums.begin() + size % k);
		for (int i = 0; i < k; ++i) {
			nums[i] = nums[i + size % k];
		}
		for (int i = 0; i < size % k; ++i) {
			nums[k + i] = temp[i];
		}
	}
};
#endif //LEETCODE_N189_H
