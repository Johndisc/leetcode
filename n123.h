//
// Created by 58253 on 2023/1/12.
//

#ifndef LEETCODE_N123_H
#define LEETCODE_N123_H
#include "global.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int total = 0;
        int leftmax = 0, leftmin = prices[0];
        vector<int> rightprice(prices.size(), 0);
        int rightmax = prices[prices.size() - 1];
        for (int i = prices.size() - 2; i >= 0; --i) {
            if (prices[i] > rightmax) {
                rightmax = prices[i];
                rightprice[i] = rightprice[i + 1];
            }
            else
                rightprice[i] = max(rightprice[i + 1], rightmax - prices[i]);
        }
        for (int i = 1; i < prices.size() - 1; ++i) {
            if (prices[i] < leftmin)
                leftmin = prices[i];
            else
                leftmax = max(leftmax, prices[i] - leftmin);
            if (prices[i] >= prices[i - 1] && prices[i] >= prices[i + 1]) {
                total = max(total, leftmax + rightprice[i + 1]);
            }
        }
        total = max(total, prices[prices.size() - 1] - leftmin);
        return total;
    }
};
#endif //LEETCODE_N123_H
