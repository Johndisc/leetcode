//
// Created by 58253 on 2022/10/2.
//

#ifndef LEETCODE_N217_H
#define LEETCODE_N217_H

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
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> map;
        for (auto item: nums) {
            if (map.count(item))
                return true;
            map.insert(item);
        }
        return false;
    }
};
#endif //LEETCODE_N217_H
