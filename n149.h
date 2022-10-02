//
// Created by 58253 on 2022/9/23.
//

#ifndef LEETCODE_N149_H
#define LEETCODE_N149_H

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
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() == 1)
            return 1;
        int maxnum = 0;
        for (int i = 0; i < points.size() - 1; ++i) {
            unordered_map<double, int> cnt;
            int col = 0;
            for (int j = i + 1; j < points.size(); ++j) {
                if (points[j][0] == points[i][0]) {
                    col++;
                    maxnum = max(maxnum, col);
                }
                else {
                    double slope = 1.0 * (points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
                    cnt[slope]++;
                    maxnum = max(maxnum, cnt[slope]);
                }

            }
        }
        return maxnum + 1;
    }
};
#endif //LEETCODE_N149_H
