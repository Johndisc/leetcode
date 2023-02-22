//
// Created by CGCL on 2023/2/22.
//

#ifndef LEETCODE_N201_H
#define LEETCODE_N201_H
#include "global.h"

class Solution {
public:
	int rangeBitwiseAnd(int left, int right) {
		int cnt = 0;
		while (left != right) {
			left = left >> 1;
			right = right >> 1;
			cnt++;
		}
		return left << cnt;
	}
};
#endif //LEETCODE_N201_H
