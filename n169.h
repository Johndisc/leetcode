//
// Created by 58253 on 2022/9/24.
//

#ifndef LEETCODE_N169_H
#define LEETCODE_N169_H

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
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> times;
        for (auto item: nums) {
            times[item]++;
            if (times[item] > nums.size() / 2)
                return item;
        }
        return 0;
    }
};
#endif //LEETCODE_N169_H
