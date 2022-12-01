//
// Created by 58253 on 2022/12/1.
//

#ifndef LEETCODE_N349_H
#define LEETCODE_N349_H

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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> table;
        for (auto i: nums1) {
            table.insert(i);
        }
        vector<int> res;
        for (auto i: nums2) {
            if (table.count(i)) {
                table.erase(i);
                res.push_back(i);
            }
        }
        return res;
    }
};
#endif //LEETCODE_N349_H
