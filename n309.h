//
// Created by CGCL on 2023/2/27.
//

#ifndef LEETCODE_N309_H
#define LEETCODE_N309_H
#include "global.h"

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int sz = prices.size();
		if (sz == 1)
			return 0;
		int buy[sz], sell[sz], lastsell[sz];
		buy[0] = -prices[0];
		buy[1] = max(-prices[0], -prices[1]);
		sell[0] = 0;
		sell[1] = 0;
		lastsell[0] = 0;
		lastsell[1] = prices[1] - prices[0];
		for (int i = 2; i < sz; ++i) {
			buy[i] = max(buy[i - 1], sell[i - 2] - prices[i]);
			buy[i] = max(buy[i], lastsell[i - 2] - prices[i]);
			sell[i] = max(sell[i - 1], lastsell[i - 1]);
			lastsell[i] = buy[i - 1] + prices[i];
		}
		return max(sell[sz - 1], lastsell[sz - 1]);
	}
};
#endif //LEETCODE_N309_H
