//
// Created by 58253 on 2022/12/23.
//

#ifndef LEETCODE_N69_H
#define LEETCODE_N69_H
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
    int mySqrt(int x) {
        if (x == 1)
            return 1;
        int s = 0, e = x, mid;
        while (1) {
            mid = (s + e) / 2;
            if (pow(mid, 2) <= x && pow(mid + 1, 2) > x)
                return mid;
            else if (pow(mid, 2) > x)
                e = mid;
            else
                s = mid;
        }
    }
};
#endif //LEETCODE_N69_H
