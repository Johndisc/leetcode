//
// Created by 58253 on 2023/1/12.
//

#ifndef LEETCODE_N122_H
#define LEETCODE_N122_H
#include "global.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0], total = 0;
        bool bought = false;
        for (int i = 1; i < prices.size(); ++i) {
            if (bought && prices[i] < prices[i - 1]) {
                total += prices[i - 1] - buy;
                bought = false;
            }
            else if (!bought && prices[i] > prices[i - 1]) {
                buy = prices[i - 1];
                bought = true;
            }
        }
        if (bought)
            total += prices[prices.size() - 1] - buy;
        return total;
    }
};
#endif //LEETCODE_N122_H
