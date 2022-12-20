//
// Created by 58253 on 2022/12/20.
//

#ifndef LEETCODE_N50_H
#define LEETCODE_N50_H

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
    double compute(double x, long long n) {
        if (n == 1)
            return x;
        if (n % 2) {
            double mid = compute(x, (n - 1) / 2);
            return x * mid * mid;
        }
        else {
            double mid = compute(x, n / 2);
            return mid * mid;
        }
    }

    double myPow(double x, int n) {
        if (n == 0)
            return 1.0;
        bool isMin = n < 0;
        long long nn = n;
        nn = abs(nn);
        if (isMin)
            return 1.0 / compute(x, nn);
        else
            return compute(x, nn);
    }
};
#endif //LEETCODE_N50_H
