//
// Created by 58253 on 2022/11/30.
//

#ifndef LEETCODE_N347_H
#define LEETCODE_N347_H

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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> times;
        map<int, vector<int>> sorted;
        for (auto i:nums) {
            times[i]++;
        }
        vector<int> res;
        for (auto item: times) {
            sorted[item.second].push_back(item.first);
        }
        for (auto it = sorted.rbegin(); it != sorted.rend(); it++) {
            res.insert(res.end(), it->second.begin(), it->second.end());
            k -= it->second.size();
            if (k == 0)
                break;
        }
        return res;
    }
};
#endif //LEETCODE_N347_H
