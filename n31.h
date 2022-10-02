//
// Created by 58253 on 2022/6/16.
//

#ifndef LEETCODE_N31_H
#define LEETCODE_N31_H
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        auto it = nums.end() - 1;
        while (it > nums.begin() && *(it - 1) >= *it)
            it--;
        if (it == nums.begin()) {
            reverse(nums.begin(), nums.end());
        } else {
            for (auto sec = nums.end() - 1; sec >= it; sec--) {
                if (*sec > *(it - 1)) {
                    int mid = *sec;
                    *sec = *(it - 1);
                    *(it - 1) = mid;
                    reverse(it, nums.end());
                    return;
                }
            }
        }
    }
};
#endif //LEETCODE_N31_H
