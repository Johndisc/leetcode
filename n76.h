//
// Created by 58253 on 2022/8/17.
//

#ifndef LEETCODE_N76_H
#define LEETCODE_N76_H
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
    string minWindow(string s, string t) {
        unordered_map<char, int> tcnt;
        unordered_map<char, int> scnt;
        for (char &c:t)
            tcnt[c]++;
        for (char &c:s)
            scnt[c]++;
        for (auto item:tcnt)
            if (scnt[item.first] < item.second)
                return "";
        int ms = 0, me = s.size() - 1;
        while (true) {
            if (scnt[s[me]] - 1 >= tcnt[s[me]]) {
                scnt[s[me]]--;
                me--;
            } else
                break;
        }
        while (true) {
            if (scnt[s[ms]] - 1 >= tcnt[s[ms]]) {
                scnt[s[ms]]--;
                ms++;
            } else
                break;
        }
        int ns = ms, ne = me;
        int lack = 0;
        while (me != s.size()) {
            //移动窗口
            scnt[s[ms]]--;
            if (scnt[s[ms]] < tcnt[s[ms]])
                lack++;
            ms++;
            if (scnt[s[me + 1]] < tcnt[s[me + 1]])
                lack--;
            me++;
            scnt[s[me]]++;

            //缩减窗口
            if (lack == 0) {
                while (true) {
                    if (scnt[s[ms]] - 1 >= tcnt[s[ms]]) {
                        scnt[s[ms]]--;
                        ms++;
                    } else
                        break;
                }
                ns = ms;
                ne = me;
            }
        }
        return s.substr(ns, ne - ns + 1);
    }
};
#endif //LEETCODE_N76_H
