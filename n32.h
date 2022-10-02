//
// Created by 58253 on 2022/8/12.
//

#ifndef LEETCODE_N32_H
#define LEETCODE_N32_H

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
    int longestValidParentheses(string s) {
        stack<short> index_stack;
        vector<bool> active(s.size(), false);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(')
                index_stack.push(i);
            else if (s[i] == ')') {
                if (!index_stack.empty()) {
                    active[i] = true;
                    active[index_stack.top()] = true;
                    index_stack.pop();
                }
            }
        }

        int maxlen = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (active[i]) {
                int cnt = 0;
                while (i < s.size() && active[i]) {
                    i++;
                    cnt++;
                }
                maxlen = max(maxlen, cnt);
            }
        }
        return maxlen;
    }
};
#endif //LEETCODE_N32_H
