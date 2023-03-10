//
// Created by 58253 on 2023/3/5.
//

#ifndef LEETCODE_N227_H
#define LEETCODE_N227_H
#include "global.h"

class Solution {
public:
    unordered_map<char, int> ops{{'+', -1},
                                 {'-', -2},
                                 {'*', -3},
                                 {'/', -4}};

    int calculate(string s) {
        stack<int> stk;
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                int k = i + 1;
                while (k < s.size() && isdigit(s[k]))
                    k++;
                if (!stk.empty() && (stk.top() == -3 || stk.top() == -4)) {
                    int op = stk.top();
                    stk.pop();
                    int num = stk.top();
                    stk.pop();
                    if (op == -3)
                        stk.push(num * stoi(s.substr(i, k - i)));
                    else
                        stk.push(num / stoi(s.substr(i, k - i)));
                }
                else
                    stk.push(stoi(s.substr(i, k - i)));
                i = k - 1;
            }
            else if (s[i] == ' ')
                continue;
            else if (s[i] == '(') {
                int k = i + 1;
                int cnt = 1;
                while (cnt) {
                    if (s[k] == '(')
                        cnt++;
                    else if (s[k] == ')')
                        cnt--;
                    k++;
                }
                if (!stk.empty() && (stk.top() == -3 || stk.top() == -4)) {
                    int op = stk.top();
                    stk.pop();
                    int num = stk.top();
                    stk.pop();
                    if (op == -3)
                        stk.push(num * calculate(s.substr(i + 1, k - i - 2)));
                    else
                        stk.push(num / calculate(s.substr(i + 1, k - i - 2)));
                }
                else
                    stk.push(calculate(s.substr(i + 1, k - i - 2)));
                i = k - 1;
            }
            else
                stk.push(ops[s[i]]);
        }
        stack<int> ns;
        while (!stk.empty()) {
            ns.push(stk.top());
            stk.pop();
        }
        int res = ns.top();
        ns.pop();
        while (!ns.empty()) {
            int op = ns.top();
            ns.pop();
            int num = ns.top();
            ns.pop();
            if (op == -1)
                res += num;
            else
                res -= num;
        }
        return res;
    }
};
#endif //LEETCODE_N227_H
