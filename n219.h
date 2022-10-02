//
// Created by 58253 on 2022/10/2.
//

#ifndef LEETCODE_N219_H
#define LEETCODE_N219_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> table;
        for (int i = 0; i < nums.size(); ++i) {
            if (table.find(nums[i]) != table.end() && i - table[nums[i]] <= k)
                return true;
            table[nums[i]] = i;
        }
        return false;
    }
};
#endif //LEETCODE_N219_H
