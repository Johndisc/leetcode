//
// Created by 58253 on 2023/1/13.
//

#ifndef LEETCODE_N134_H
#define LEETCODE_N134_H
#include "global.h"

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int i = 0; i < n; ++i) {
            if (gas[i] >= cost[i]) {
                int base_oil = gas[i] - cost[i], j;
                for (j = 1; j < n; ++j) {
                    i++;
                    base_oil += gas[i % n] - cost[i % n];
                    if (base_oil < 0)
                        break;
                }
                if (base_oil >= 0)
                    return (i + 1) % n;
            }
        }
        return -1;
    }
};
#endif //LEETCODE_N134_H
