//
// Created by 58253 on 2022/8/16.
//

#ifndef LEETCODE_N44_TODO_DP_H
#define LEETCODE_N44_TODO_DP_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <stack>
#include <map>

using namespace std;
class Solution {
public:
    bool match(string &s, int m, string &p, int n) {
        printf("%d %d\n", m, n);
        while (m < s.size() && n < p.size()) {
            if (p[n] == '?' || s[m] == p[n]) {
                m++;
                n++;
            }
            else if (p[n] == '*') {
                if (n == p.size() - 1)
                    return true;
                else {
                    for (int i = m; i < s.size(); ++i) {
                        if ((p[n + 1] == '?' || s[i] == p[n + 1]) && match(s, i + 1, p, n + 2))
                            return true;
                    }
                    return false;
                }
            }
            else
                return false;
        }
        if (m == s.size() && n == p.size())
            return true;
        else if (m == s.size()) {
            for (int i = n; i < p.size(); ++i) {
                if (p[i] != '*')
                    return false;
            }
            return true;
        }
        else
            return false;
    }
    bool isMatch(string s, string p) {
        string np;
        char last = ' ';
        for (char c: p) {
            if (c == '*' && last == '*')
                continue;
            np.append(1, c);
            last = c;
        }
        return match(s, 0, np, 0);
    }
};
#endif //LEETCODE_N44_TODO_DP_H
