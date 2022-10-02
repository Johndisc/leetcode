//
// Created by 58253 on 2022/8/17.
//

#ifndef LEETCODE_N93_H
#define LEETCODE_N93_H
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
    vector<string> res;

    void findRes(string s, int start, int dot_cnt) {
        if (dot_cnt == 3) {
            cout << s << endl;
            cout << s.substr(start);
            int num = stoi(s.substr(start));
            if (start < s.size() && num <= 255) {
                if (s[start] == '0' && (num != 0 || start != s.size() - 1))
                    return;
                res.push_back(s);
                return;
            } else {
                return;
            }
        }

        if (s.size() - start > 1) {
            s.insert(start + 1, ".");
            findRes(s, start + 2, dot_cnt + 1);
            s.erase(start + 1, 1);

            if (s[start] != '0') {
                if (s.size() - start > 2) {
                    s.insert(start + 2, ".");
                    findRes(s, start + 3, dot_cnt + 1);
                    s.erase(start + 2, 1);
                }

                if (s.size() - start > 3 && stoi(s.substr(start, 3)) <= 255) {
                    s.insert(start + 3, ".");
                    findRes(s, start + 4, dot_cnt + 1);
                    s.erase(start + 3, 1);
                }
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        if (s.size() > 12)
            return res;
        findRes(s, 0, 0);
        return res;
    }
};
#endif //LEETCODE_N93_H
