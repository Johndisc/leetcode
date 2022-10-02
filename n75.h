//
// Created by 58253 on 2022/8/7.
//

#ifndef LEETCODE_N75_H
#define LEETCODE_N75_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s = 0, e = nums.size() - 1;
        int sw = s, ew = e;
        while (s <= ew) {
            if (nums[s] == 0) {
                swap(nums[s++], nums[sw++]);
            }
            else if (nums[s] == 1) {
                s++;
            }
            else if (nums[s] == 2) {
                swap(nums[s], nums[ew--]);
                while (ew >= 0 && nums[ew] == 2)
                    ew--;
            }
        }
    }
};
#endif //LEETCODE_N75_H
