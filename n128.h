//
// Created by 58253 on 2022/9/19.
//

#ifndef LEETCODE_N128_H
#define LEETCODE_N128_H

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
    int longestConsecutive(vector<int>& nums) {
        set<int> nset;
        for (int &i:nums)
            nset.insert(i);
        int last = -10000000001;
        int length = 1;
        int maxlen = 0;
        for (auto item:nset) {
            if (item - last == 1)
                length++;
            else
                length = 1;
            maxlen = max(maxlen, length);
            last = item;
        }
        return maxlen;
    }
};
#endif //LEETCODE_N128_H
