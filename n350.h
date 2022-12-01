//
// Created by 58253 on 2022/12/1.
//

#ifndef LEETCODE_N350_H
#define LEETCODE_N350_H

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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> table;
        for (auto i: nums1) {
            table[i]++;
        }
        vector<int> res;
        for (auto i: nums2) {
            if (table[i]) {
                res.push_back(i);
                table[i]--;
            }
        }
        return res;
    }
};
#endif //LEETCODE_N350_H
