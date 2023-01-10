//
// Created by 58253 on 2023/1/10.
//

#ifndef LEETCODE_N118_H
#define LEETCODE_N118_H
#include "global.h"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows == 0)
            return res;
        vector<int> row;
        for (int i = 0; i < numRows; ++i) {
            row.push_back(1);
            for (int j = 1; j <= i; ++j) {
                if (j < (i / 2 + 1))
                    row.push_back(res.back()[j - 1] + res.back()[j]);
                else
                    row.push_back(row[i - j]);
            }
            res.push_back(row);
            row.clear();
        }
        return res;
    }
};
#endif //LEETCODE_N118_H
