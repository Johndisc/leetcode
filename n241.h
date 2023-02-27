//
// Created by CGCL on 2023/2/27.
//

#ifndef LEETCODE_N241_H
#define LEETCODE_N241_H
#include "global.h"

class Solution {
public:
	vector<int> nums;
	vector<char> ops;
	
	int computeOne(int x, int y, char op) {
		if (op == '+')
			return x + y;
		else if (op == '-')
			return x - y;
		else
			return x * y;
	}
	
	void merge(vector<int> &dest, vector<int> &v1, vector<int> &v2, char op) {
		for (auto i: v1) {
			for (auto j:v2) {
				dest.push_back(computeOne(i, j, op));
			}
		}
	}
	
	vector<int> diffWaysToCompute(string expression) {
		int pos = 0;
		while (!expression.empty() && pos < expression.size()) {
			if (!isdigit(expression[pos])) {
				nums.emplace_back(stoi(expression.substr(0, pos)));
				ops.push_back(expression[pos]);
				expression.erase(0, pos + 1);
				pos = 0;
			}
			else
				pos++;
		}
		nums.emplace_back(stoi(expression));
		if (nums.size() == 1)
			return nums;
		
		vector<int> ans[nums.size()][nums.size() + 1];
		for (int i = 0; i < nums.size(); ++i)
			ans[i][1].push_back(nums[i]);
		for (int i = 0; i < nums.size() - 1; ++i)
			ans[i][2].push_back(computeOne(nums[i], nums[i + 1], ops[i]));
		
		for (int i = 3; i <= nums.size(); ++i) {
			for (int j = 0; j < nums.size() - i + 1; ++j) {
				for (int k = 1; k < i ; ++k) {
					merge(ans[j][i], ans[j][k], ans[j + k][i - k], ops[j + k - 1]);
				}
			}
		}
		
		return ans[0][nums.size()];
	}
};
#endif //LEETCODE_N241_H
