//
// Created by 58253 on 2022/8/15.
//

#ifndef LEETCODE_N38_H
#define LEETCODE_N38_H

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
    string transform(string s) {
        int cnt;
        char last = ' ';
        string res;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == last) {
                cnt++;
            }
            else {
                if (last != ' ') {
                    res.append(to_string(cnt));
                    res.append(1, last);
                }
                cnt = 1;
                last = s[i];
            }
        }
        res.append(to_string(cnt));
        res.append(1, last);
        return res;
    }
    string countAndSay(int n) {
        string res("1");
        for (int i = 0; i < n - 1; ++i) {
            res = transform(res);
        }
        return res;
    }
};
#endif //LEETCODE_N38_H
