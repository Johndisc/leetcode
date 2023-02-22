//
// Created by CGCL on 2023/2/22.
//

#ifndef LEETCODE_N207_H
#define LEETCODE_N207_H
#include "global.h"

class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<bool> bitmap(numCourses, true);
		unordered_map<int,unordered_set<int>> precourse;
		unordered_map<int,unordered_set<int>> inverse;
		for (auto item: prerequisites) {
			precourse[item[1]].insert(item[0]);
			inverse[item[0]].insert(item[1]);
			bitmap[item[0]] = false;
		}
		bool finished = false;
		while (!finished) {
			finished = true;
			for (int i = 0; i < numCourses; ++i) {
				if (bitmap[i]) {
					for (auto item: precourse[i]) {
						inverse[item].erase(i);
						if (inverse[item].empty()) {
							bitmap[item] = true;
							inverse.erase(item);
							finished = false;
						}
					}
					bitmap[i] = false;
				}
			}
		}
		return inverse.empty();
	}
};
#endif //LEETCODE_N207_H
