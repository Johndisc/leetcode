//
// Created by 58253 on 2022/10/2.
//

#ifndef LEETCODE_N229_H
#define LEETCODE_N229_H

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
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> table;
        set<int> res;
        for (int it: nums) {
            table[it]++;
            if (table[it] > nums.size() / 3) {
                res.insert(it);
            }
        }
        vector<int> ans(res.begin(), res.end());
        return ans;
    }
};
#endif //LEETCODE_N229_H
