//
// Created by 58253 on 2022/6/10.
//

#ifndef LEETCODE_N730_H
#define LEETCODE_N730_H

#include <iostream>
#include <set>
#include <cmath>

using namespace std;

class Solution {
public:
    set<char> ch{'a', 'b', 'c', 'd'};
    int sum = 0;
    bool findSub(const string& src, const string& dst)
    {
        int i = 0;
        for (char j : src) {
            if (j == dst[i]) {
                i++;
                if (i == dst.size())
                    return true;
            }
        }
        return false;
    }

    void construct(const string &src, string &dst, int half_len, int depth) {
        if (depth == half_len) {
            if (findSub(src, dst))
                sum = (sum + 1) % static_cast<int>((pow(10, 9) + 7));
            return;
        }
        for (auto item: ch) {
            dst[depth] = item;
            dst[dst.size() - depth - 1] = item;
            construct(src, dst, half_len, depth + 1);
        }
    }
    int countPalindromicSubsequences(string s) {
        int half_len = 1;
        string dst(1 + (half_len - 1) * 2, ' ');
        while (dst.size() <= s.size()) {
            construct(s, dst, half_len, 0);
            dst.resize(2 * half_len, ' ');
            if (dst.size()>s.size())
                break;
            construct(s, dst, half_len, 0);
            half_len++;
            dst.resize(1 + (half_len - 1) * 2, ' ');
        }
        return sum;
    }
};

#endif //LEETCODE_N730_H
