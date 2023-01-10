//
// Created by 58253 on 2023/1/10.
//

#ifndef LEETCODE_N119_H
#define LEETCODE_N119_H
#include "global.h"

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> rows(2);
        for (int i = 0; i <= rowIndex; ++i) {
            rows[i % 2].push_back(1);
            for (int j = 1; j <= i; ++j) {
                if (j < (i / 2 + 1))
                    rows[i % 2].push_back(rows[1 - i % 2][j - 1] + rows[1 - i % 2][j]);
                else
                    rows[i % 2].push_back(rows[i % 2][i - j]);
            }
            rows[1 - i % 2].clear();
        }
        return rows[rowIndex % 2];
    }
};
#endif //LEETCODE_N119_H
