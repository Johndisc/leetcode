//
// Created by CGCL on 2023/3/3.
//

#ifndef LEETCODE_N406_H
#define LEETCODE_N406_H
#include "global.h"

class Solution {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		sort(people.begin(), people.end(), [](const vector<int> &p1, const vector<int> &p2) {
			return p1[0] == p2[0] ? p1[1] < p2[1] : p1[0] > p2[0];
		});
		list<vector<int> > sorted;
		for (auto ppl: people) {
			auto it = sorted.cbegin();
			for (int i = 0; i < ppl[1]; ++i)
				it++;
			sorted.insert(it, ppl);
		}
		vector <vector<int>> res(sorted.begin(), sorted.end());
		return res;
	}
};
#endif //LEETCODE_N406_H
