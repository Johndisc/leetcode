//
// Created by 58253 on 2022/12/26.
//

#ifndef LEETCODE_N84_TODO_MONOTONIC_STACK_H
#define LEETCODE_N84_TODO_MONOTONIC_STACK_H
#include "global.h"

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size(), mx = 0;
        int low[size][size + 1], area[size][size + 1];
        for (int i = 0; i < size; ++i) {
            low[i][1] = heights[i];
        }
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 2; j <= size - i; ++j) {
                low[i][j] = min(low[i][j - 1], heights[i + j - 1]);
            }
        }
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 1; j <= size - i; ++j) {
                area[i][j] = j * low[i][j];
                mx = max(area[i][j], mx);
            }
        }
        return mx;
    }
};
#endif //LEETCODE_N84_TODO_MONOTONIC_STACK_H
