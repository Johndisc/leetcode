//
// Created by 58253 on 2023/1/1.
//

#ifndef LEETCODE_N88_H
#define LEETCODE_N88_H
#include "global.h"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < n; ++i)
            nums1[m + i] = nums2[i];
        sort(nums1.begin(), nums1.end());
    }
};
#endif //LEETCODE_N88_H
