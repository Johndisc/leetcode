//
// Created by 58253 on 2022/9/28.
//

#ifndef LEETCODE_N202_H
#define LEETCODE_N202_H

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
    int trans(int n) {
        int res = 0;
        while (n) {
            int x = n % 10;
            res += x * x;
            n /= 10;
        }
        return res;
    }

    bool isHappy(int n) {
        set<int> nums;
        while (!nums.count(n)) {
            if (n == 1)
                return true;
            nums.insert(n);
            n = trans(n);
        }
        return false;
    }
};
#endif //LEETCODE_N202_H
