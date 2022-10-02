//
// Created by 58253 on 2022/7/8.
//

#ifndef LEETCODE_N56_H
#define LEETCODE_N56_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        vector<int> start(intervals.size()), end(intervals.size());
        for (int i = 0; i < intervals.size(); ++i) {
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        start.push_back(100000);
        end.push_back(100000);
        int s = start[0], e = end[0];
        for (int i = 0; i <= intervals.size(); ++i)
        {
            if (e < start[i]) {
                res.push_back(vector<int>{s, e});
                s = start[i];
            }
            e = end[i];
        }
        return res;
    }
};
#endif //LEETCODE_N56_H
