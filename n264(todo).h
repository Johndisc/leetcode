//
// Created by 58253 on 2022/10/2.
//

#ifndef LEETCODE_N264_TODO_H
#define LEETCODE_N264_TODO_H

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
    set<int> ugly;
    bool isUgly(int n) {
        while (n != 2 && n != 3 && n != 5) {
            if (ugly.count(n))
                return true;
            else if (n % 2 == 0)
                n /= 2;
            else if (n % 3 == 0)
                n /= 3;
            else if (n % 5 == 0)
                n /= 5;
            else
                return false;
        }
        return true;
    }

    struct multipler {
        int n;
        multipler(int n_) : n(n_) {
        }
        int operator() (int m) const{
            return m + n;
        }
    };

    int getUgly(int n) {
        int last = 1;
        while (ugly.size() < n) {
            int tmp = *ugly.rbegin();
            auto begin = ugly.find(last);
            ++begin;
            auto end = ugly.end();
            for (int i : {2,3,4,5}) {
                transform(begin, end, std::inserter(ugly, ugly.begin()), multipler(i));
            }
            auto it = ugly.find(tmp);
            last = *++it;
        }
        auto it = ugly.begin();
        advance(it, n);
        return *it;
    }

    int nthUglyNumber(int n) {
        ugly.insert(1);
        return getUgly(n);
    }
};

#endif //LEETCODE_N264_TODO_H
