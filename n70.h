//
// Created by 58253 on 2022/12/23.
//

#ifndef LEETCODE_N70_H
#define LEETCODE_N70_H
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
    int climbStairs(int n) {
        int cnt[n + 1];
        cnt[0] = 1;
        cnt[1] = 1;
        for (int i = 2; i < n + 1; ++i) {
            cnt[i] = cnt[i - 1] + cnt[i - 2];
        }
        return cnt[n];
    }
};
#endif //LEETCODE_N70_H
