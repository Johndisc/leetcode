//
// Created by 58253 on 2023/1/12.
//

#ifndef LEETCODE_N121_H
#define LEETCODE_N121_H
#include "global.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minnum = prices[0];
        int res = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < minnum)
                minnum = prices[i];
            else
                res = max(res, prices[i] - minnum);
        }
        return res;
    }
};
#endif //LEETCODE_N121_H
