//
// Created by 58253 on 2022/12/23.
//

#ifndef LEETCODE_N77_H
#define LEETCODE_N77_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <map>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    void findRes(vector<int> &num, vector<int> &cur, int s, int k) {
        if (k == 0) {
            res.push_back(cur);
            return;
        }
        for (int i = s; i < num.size() - k + 1; ++i) {
            cur.push_back(num[i]);
            findRes(num, cur, i + 1, k - 1);
            cur.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> num(n), cur;
        for (int i = 0; i < n; ++i) {
            num[i] = i + 1;
        }
        findRes(num, cur, 0, k);
        return res;
    }
};
#endif //LEETCODE_N77_H
