//
// Created by 58253 on 2022/6/15.
//

#ifndef LEETCODE_N26_H
#define LEETCODE_N26_H
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sum = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[sum])
            {
                sum++;
                nums[sum] = nums[i];
            }
        }
        return sum + 1;
    }
};

#endif //LEETCODE_N26_H
