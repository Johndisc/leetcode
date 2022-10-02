//
// Created by 58253 on 2022/7/3.
//

#ifndef LEETCODE_N42_H
#define LEETCODE_N42_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        int sum = 0, highest = 0;
        for (int & i : height)
            highest = max(highest, i);
        int s = 0, e = height.size() - 1;
        int ch = height[0];
        while (height[s] < highest) {
            if (height[s] < ch)
                sum += ch - height[s];
            else
                ch = height[s];
            s++;
        }
        ch = height[e];
        while (height[e] < highest) {
            if (height[e] < ch)
                sum += ch - height[e];
            else
                ch = height[e];
            e--;
        }
        for (int i = s; i < e; ++i) {
            sum += highest - height[i];
        }
        return sum;
    }
};
#endif //LEETCODE_N42_H
