//
// Created by CGCL on 2023/2/22.
//

#ifndef LEETCODE_N191_H
#define LEETCODE_N191_H
#include "global.h"

class Solution {
public:
	int hammingWeight(uint32_t n) {
		uint32_t one = 0x00000001;
		int cnt = 0;
		for (int i = 0; i < 32; ++i) {
			if (n & one)
				cnt++;
			n = n >> 1;
		}
		return cnt;
	}
};
#endif //LEETCODE_N191_H
