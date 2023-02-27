//
// Created by CGCL on 2023/2/12.
//

#ifndef LEETCODE_N188_H
#define LEETCODE_N188_H
#include "global.h"

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
		int sz = prices.size();
		int lastin[sz][k+1], lastout[sz][k+1];
		lastin[0][0] = -prices[0];
		lastout[0][0] = 0;
		for (int i = 1; i < sz; ++i) {
			lastin[i][0] = max(-prices[i], lastin[i - 1][0]);
			lastout[i][0] = 0;
		}
		for (int i = 1; i <= k; ++i) {
			lastin[0][i] = INT_MIN/2;
			lastout[0][i] = INT_MIN/2;
		}
		
		for (int i = 1; i < prices.size(); ++i) {
			for (int j = 1; j <= k; ++j) {
				lastin[i][j] = max(lastin[i - 1][j], lastout[i - 1][j] - prices[i]);
				lastout[i][j] = max(lastin[i - 1][j - 1] + prices[i], lastout[i - 1][j]);
			}
		}
		int profit = 0;
		for (int i = 1; i <= k; ++i) {
			profit = max(profit, lastout[sz - 1][i]);
		}
		return profit;
    }
};
#endif //LEETCODE_N188_H
