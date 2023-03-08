//
// Created by CGCL on 2023/3/3.
//

#ifndef LEETCODE_N394_H
#define LEETCODE_N394_H
#include "global.h"

class Solution {
public:
	string decodeString(string s) {
		int i = 0, j = 0, k;
		string res;
		while (i < s.size()) {
			if (isdigit(s[i])) {
				res += s.substr(j, i - j);
				j = i + 1;
				while (j < s.size() && isdigit(s[j]))
					j++;
				if (j == s.size())
					return res;
				int num = stoi(s.substr(i, j - i));
				k = j + 1;
				int left = 1;
				while (left != 0) {
					if (s[k] == '[')
						left++;
					else if (s[k] == ']')
						left--;
					k++;
				}
				string sub = decodeString(s.substr(j + 1, k - j - 2));
				for (int l = 0; l < num; ++l)
					res += sub;
				i = k;
				j = i;
				continue;
			}
			i++;
		}
		res += s.substr(j, i - j);
		return res;
	}
};
#endif //LEETCODE_N394_H
