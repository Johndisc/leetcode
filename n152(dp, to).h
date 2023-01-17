//
// Created by 58253 on 2023/1/17.
//

#ifndef LEETCODE_N152_DP_TO_H
#define LEETCODE_N152_DP_TO_H
#include "global.h"

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mul = 1, maxmul = INT_MIN, s = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                if (mul > 0)
                    maxmul = max(maxmul, mul);
                else {
                    int mid = 1;
                    for (int j = s; j < i; ++j) {
                        if (nums[j] < 0) {
                            maxmul = max(maxmul, mid);
                            maxmul = max(maxmul, (mul / mid) / nums[i]);
                            break;
                        }
                        mid *= nums[j];
                    }
                    mid = 1;
                    for (int j = i - 1; j >= s; --j) {
                        if (nums[j] < 0) {
                            maxmul = max(maxmul, mid);
                            maxmul = max(maxmul, (mul / mid) / nums[i]);
                        }
                        mid *= nums[j];
                    }
                }
                mul = 1;
                s = i + 1;
            }
            else
                mul *= nums[i];
        }
        return maxmul;
    }
};
#endif //LEETCODE_N152_DP_TO_H
