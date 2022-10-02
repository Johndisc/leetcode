//
// Created by 58253 on 2022/7/7.
//

#ifndef LEETCODE_N53_H
#define LEETCODE_N53_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    int findres(vector<int>& nums,int s,int e) {
        if (s >= e)
            return nums[s];
        int mid = (s + e) / 2;
        int maxnum = nums[mid], sum = 0;
        int i = mid;
        while (i >= s) {
            sum += nums[i];
            maxnum = max(maxnum, sum);
            i--;
        }
        i = mid + 1;
        sum = maxnum;
        while (i <= e) {
            sum += nums[i];
            maxnum = max(maxnum, sum);
            i++;
        }
        maxnum = max(maxnum, findres(nums, s, mid - 1));
        maxnum = max(maxnum, findres(nums, mid + 1, e));
        return maxnum;
    }
    int maxSubArray(vector<int>& nums) {
        return findres(nums, 0, nums.size() - 1);
    }
};
#endif //LEETCODE_N53_H
