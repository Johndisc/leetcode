//
// Created by 58253 on 2022/8/18.
//

#ifndef LEETCODE_N97_TODO_DP_H
#define LEETCODE_N97_TODO_DP_H
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
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size();
        int l2 = s2.size();
        int l3 = s3.size();
        if (l3 != l1 + l2)
            return false;
        int j = 0;
        for (int i = 0; i < l3; ++i) {
            if (j == s2.size())
                break;
            if (s3[i] == s2[j]) {
                s3.erase(i, 1);
                i--;
                j++;
            }
        }
        if (s1 == s3 && j == s2.size())
            return true;
        else
            return false;
    }
};
#endif //LEETCODE_N97_TODO_DP_H
