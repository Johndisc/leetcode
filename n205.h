//
// Created by 58253 on 2022/9/18.
//

#ifndef LEETCODE_N205_H
#define LEETCODE_N205_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <map>

using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> smap, tmap;
        int c = 0;
        for (auto &item: s) {
            if (smap.find(item) == smap.end()) {
                smap[item] = 'a' + c;
                item = 'a' + c;
                c++;
            }
            else
                item = smap[item];
        }
        c = 0;
        for (auto &item: t) {
            if (tmap.find(item) == tmap.end()) {
                tmap[item] = 'a' + c;
                item = 'a' + c;
                c++;
            }
            else
                item = tmap[item];
        }
        return s == t;
    }
};
#endif //LEETCODE_N205_H
