//
// Created by 58253 on 2022/10/8.
//

#ifndef LEETCODE_N268_H
#define LEETCODE_N268_H

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
    int missingNumber(vector<int>& nums) {
        unordered_set<int> table;
        for (auto &it: nums)
            table.insert(it);
        for (int i = 0; i <= nums.size(); ++i) {
            if (!table.count(i))
                return i;
        }
        return 0;
    }
};
#endif //LEETCODE_N268_H
