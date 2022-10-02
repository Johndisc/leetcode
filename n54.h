//
// Created by 58253 on 2022/7/7.
//

#ifndef LEETCODE_N54_H
#define LEETCODE_N54_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rl = 0, cd = 0, rr = 0, cu = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;
        while (true) {
            if (cu == n - cd)
                break;
            for (int i = cu; i < n - cd; ++i)
                res.push_back(matrix[rl][i]);
            rl++;
            if (rl == m - rr)
                break;
            for (int i = rl; i < m - rr; ++i)
                res.push_back(matrix[i][n - cd - 1]);
            cd++;
            if (n - cd == cu)
                break;
            for (int i = n - cd - 1; i >= cu; --i)
                res.push_back(matrix[m - rr - 1][i]);
            rr++;
            if (m - rr == rl)
                break;
            for (int i = m - rr - 1; i >= rl; --i)
                res.push_back(matrix[i][cu]);
            cu++;
        }
        return res;
    }
};
#endif //LEETCODE_N54_H
