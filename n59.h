//
// Created by 58253 on 2022/7/8.
//

#ifndef LEETCODE_N59_H
#define LEETCODE_N59_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int rl = 0, cd = 0, rr = 0, cu = 0;
        int cnum = 1;
        vector<vector<int>> matrix(n, vector<int>(n));
        while (true) {
            if (cu == n - cd)
                break;
            for (int i = cu; i < n - cd; ++i)
                matrix[rl][i] = cnum++;
            rl++;
            if (rl == n - rr)
                break;
            for (int i = rl; i < n - rr; ++i)
                matrix[i][n - cd - 1] = cnum++;
            cd++;
            if (n - cd == cu)
                break;
            for (int i = n - cd - 1; i >= cu; --i)
                matrix[n - rr - 1][i] = cnum++;
            rr++;
            if (n - rr == rl)
                break;
            for (int i = n - rr - 1; i >= rl; --i)
                matrix[i][cu] = cnum++;
            cu++;
        }
        return matrix;
    }
};
#endif //LEETCODE_N59_H
