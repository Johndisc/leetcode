//
// Created by CGCL on 2023/2/22.
//

#ifndef LEETCODE_N204_TODO_H
#define LEETCODE_N204_TODO_H
#include "global.h"

class Solution {
public:
	int countPrimes(int n) {
		if (n <= 2)
			return 0;
		if (n == 3)
			return 1;
		int cnt = 1;
		for (int i = 3; i < n; i+=2) {
			bool isprimes = true;
			for (int j = 2; j * j <= i; ++j) {
				if (i % j == 0) {
					isprimes = false;
					break;
				}
			}
			if (isprimes)
				cnt++;
		}
		return cnt;
	}
};
#endif //LEETCODE_N204_TODO_H
