//
// Created by 58253 on 2022/8/10.
//

#ifndef LEETCODE_N28_H
#define LEETCODE_N28_H

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
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;
        for (int i = 0; i < haystack.size(); ++i) {
            int j = i, k = 0;
            while (true) {
                if (k == needle.size())
                    return i;
                if (j == haystack.size() || haystack[j] != needle[k])
                    break;
                k++;
                j++;
            }
        }
        return -1;
    }
};
#endif //LEETCODE_N28_H
