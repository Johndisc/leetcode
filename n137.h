//
// Created by 58253 on 2023/1/14.
//

#ifndef LEETCODE_N137_H
#define LEETCODE_N137_H
#include "global.h"

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num: nums) {
            ++freq[num];
        }
        int ans = 0;
        for (auto [num, occ]: freq) {
            if (occ == 1) {
                ans = num;
                break;
            }
        }
        return ans;
    }
};
#endif //LEETCODE_N137_H
