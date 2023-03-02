//
// Created by CGCL on 2023/3/2.
//

#ifndef LEETCODE_N316_H
#define LEETCODE_N316_H
#include "global.h"

class Solution {
public:
	string removeDuplicateLetters(string s) {
		vector<int> times(26, 0);
		vector<bool> shown(26, false);
		
		string res;
		stack<char> stack;
		for (char c: s)
			times[c - 'a']++;
		for (char c: s) {
			if (!shown[c - 'a']) {
				while (!stack.empty() && c < stack.top() && times[stack.top() - 'a'] > 0) {
					shown[stack.top() - 'a'] = false;
					stack.pop();
				}
				shown[c - 'a'] = true;
				stack.push(c);
			}
			times[c - 'a']--;
		}
		while (!stack.empty()) {
			res.append(1, stack.top());
			stack.pop();
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
#endif //LEETCODE_N316_H
