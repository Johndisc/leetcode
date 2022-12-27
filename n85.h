//
// Created by 58253 on 2022/12/27.
//

#ifndef LEETCODE_N85_H
#define LEETCODE_N85_H
#include "global.h"

class Solution {
public:
    int largestArea(vector<int>& heights) {
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

    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> imatrix(matrix.size(), vector<int>(matrix[0].size()));
        for (int j = 0; j < matrix[0].size(); ++j)
            imatrix[0][j] = matrix[0][j] - '0';
        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == '1')
                    imatrix[i][j] = imatrix[i - 1][j] + 1;
                else
                    imatrix[i][j] = 0;
            }
        }
        int mx = 0;
        for (auto & i : imatrix) {
            mx = max(mx, largestArea(i));
        }
        return mx;
    }
};
#endif //LEETCODE_N85_H
