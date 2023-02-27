//
// Created by CGCL on 2023/2/27.
//

#ifndef LEETCODE_N233_TODO_H
#define LEETCODE_N233_TODO_H
#include "global.h"

class Solution {
public:
	int countDigitOne(int n) {
		int sum = 0;
		while (n) {
			sum += n / 10;
			if (n % 10 >= 1)
				sum++;
			n /= 10;
		}
		return sum;
	}
};
#endif //LEETCODE_N233_TODO_H
