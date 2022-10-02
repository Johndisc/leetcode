//
// Created by 58253 on 2022/6/15.
//

#ifndef LEETCODE_N27_H
#define LEETCODE_N27_H
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty())
            return 0;
        int i = 0, j = nums.size() - 1, mid;
        while (i < j) {
            if (nums[j] == val)
                j--;
            else if (nums[i] == val) {
                nums[i] = nums[j];
                i++;
                j--;
            }
            else
                i++;
        }
        if (nums[i] == val || i > j)
            return i;
        else
            return i + 1;
    }
};
#endif //LEETCODE_N27_H
