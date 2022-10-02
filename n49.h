//
// Created by 58253 on 2022/7/5.
//

#ifndef LEETCODE_N49_H
#define LEETCODE_N49_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> maps;
        for (const auto& s : strs) {
            string ns = s;
            sort(ns.begin(), ns.end());
            maps[ns].push_back(s);
        }
        for (auto item: maps) {
            res.push_back(item.second);
        }
        return res;
    }
};
#endif //LEETCODE_N49_H
