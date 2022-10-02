//
// Created by 58253 on 2022/9/13.
//

#ifndef LEETCODE_N187_H
#define LEETCODE_N187_H
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
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if (s.size() <= 10)
            return ans;
        unordered_map<string, int> times;
        times[s.substr(0, 10)] = 1;
        for (int i = 1; i <= s.size() - 10; ++i) {
            string ssub = s.substr(i, 10);
            if (times[ssub] == 1)
                ans.push_back(ssub);
            times[ssub]++;
        }
        return ans;
    }
};
#endif //LEETCODE_N187_H
