//
// Created by CGCL on 2023/2/21.
//

#ifndef LEETCODE_N190_H
#define LEETCODE_N190_H
#include "global.h"

class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t res = 0;
		for (int i = 0; i < 32; ++i){
			if (n % 2)
				res = (res << 1) + 1;
			else
				res = res << 1;
			n = n >> 1;
		}
		return res;
	}
};
#endif //LEETCODE_N190_H
