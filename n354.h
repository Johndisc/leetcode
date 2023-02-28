//
// Created by CGCL on 2023/2/28.
//

#ifndef LEETCODE_N354_H
#define LEETCODE_N354_H
#include "global.h"

class Solution {
public:
	
	int maxEnvelopes(vector<vector<int>>& envelopes) {
		sort(envelopes.begin(), envelopes.end(), [](const vector<int> &e1, const vector<int> &e2) {
			return e1[0] == e2[0] ? e1[1] < e2[1] : e1[0] < e2[0];
		});
		int length = envelopes[0][0], width = envelopes[0][1];
		vector<int> dp(envelopes.size(), 1);
		
		for (int i = 1; i < envelopes.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
				
			}
		}
		return *max_element(dp.begin(), dp.end());
	}
};
#endif //LEETCODE_N354_H
