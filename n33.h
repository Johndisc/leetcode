//
// Created by 58253 on 2022/6/17.
//

#ifndef LEETCODE_N33_H
#define LEETCODE_N33_H
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        bool isformer = target >= nums[0];
        while (s <= e) {
            int mid = (s + e) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] >= nums[0]) {
                if (isformer && target < nums[mid])
                    e = mid - 1;
                else
                    s = mid + 1;
            }
            else
            {
                if (!isformer && target > nums[mid])
                    s = mid + 1;
                else
                    e = mid - 1;
            }
        }
        return -1;
    }
};
#endif //LEETCODE_N33_H
