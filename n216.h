//
// Created by 58253 on 2023/3/5.
//

#ifndef LEETCODE_N216_H
#define LEETCODE_N216_H
#include "global.h"

class Solution {
public:
    vector<vector<int>> res;

    void dfs(int k, int s, int n, vector<int> &comb) {
        if (k == 0) {
            if (n == 0)
                res.push_back(comb);
            return;
        }
        for (int i = s; i <= 10 - k; ++i) {
            comb.push_back(i);
            dfs(k - 1, i + 1, n - i, comb);
            comb.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> comb;
        dfs(k, 1, n, comb);
        return res;
    }
};
#endif //LEETCODE_N216_H
