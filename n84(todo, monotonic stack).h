//
// Created by 58253 on 2022/12/26.
//

#ifndef LEETCODE_N84_TODO_MONOTONIC_STACK_H
#define LEETCODE_N84_TODO_MONOTONIC_STACK_H
#include "global.h"

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size(), mx = 0, width, ht;
        stack<int> mono;
        for (int i = 0; i < size; ++i) {
            while (!mono.empty() && heights[i] < heights[mono.top()]) {
                ht = mono.top();
                mono.pop();
                width = mono.empty() ? i : i - mono.top() - 1;
                mx = max(mx, heights[ht] * width);
            }
            mono.push(i);
        }
        while (!mono.empty()) {
            ht = mono.top();
            mono.pop();
            width = mono.empty() ? size : size - mono.top() - 1;
            mx = max(mx, heights[ht] * width);
        }
        return mx;
    }
};
#endif //LEETCODE_N84_TODO_MONOTONIC_STACK_H
