//
// Created by CGCL on 2023/2/22.
//

#ifndef LEETCODE_N210_H
#define LEETCODE_N210_H
#include "global.h"

class Solution {
public:
	vector<int> state;
	vector <vector<int>> edges;
	vector<int> res;
	bool valid = true;
	
	void bfs(int i) {
		state[i] = 1;
		for (auto j:edges[i]) {
			if (state[j] == 0)
				bfs(j);
			else if (state[j] == 1) {
				valid = false;
				return;
			}
		}
		state[i] = 2;
		res.push_back(i);
	}
	
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		state.resize(numCourses);
		edges.resize(numCourses);
		for (auto item: prerequisites)
			edges[item[1]].push_back(item[0]);
		for (int i = 0; i < numCourses; ++i) {
			if (!state[i])
				bfs(i);
			if (!valid)
				return {};
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
#endif //LEETCODE_N210_H
