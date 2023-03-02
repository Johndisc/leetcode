//
// Created by CGCL on 2023/3/2.
//

#ifndef LEETCODE_N215_H
#define LEETCODE_N215_H
#include "global.h"

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, less<> > pq(nums.begin(),nums.end());
		int res;
		for (int i = 0; i < k; ++i) {
			res = pq.top();
			pq.pop();
		}
		return res;
	}
};
#endif //LEETCODE_N215_H
