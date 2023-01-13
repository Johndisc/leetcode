//
// Created by 58253 on 2023/1/14.
//

#ifndef LEETCODE_N135_GREEDY_TODO_H
#define LEETCODE_N135_GREEDY_TODO_H
#include "global.h"
// 1 2 4 4 4 3       1 2 3 1 2 1
class Solution {
public:
    int candy(vector<int>& ratings) {
        int total = ratings[1] >= ratings[0] ? 1 : 0, cur = 1;
        int down = 0, up = 0, last_high = 0;
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] == ratings[i - 1]) {
                if (i < ratings.size() - 1 && ratings[i] == ratings[i + 1]) {
                    total++;
                    last_high = 1;
                }
                else if (down) {
                    total += (1 + down) * down / 2 + max(last_high, down + 1) + 1;
                    down = 0;
                }
                else if (up) {
                    total += (1 + up) * up / 2 + up;
                    last_high = 1;
                    up = 0;
                }
            }

            else if (ratings[i] > ratings[i - 1]) {
                up++;
                if (down) {
                    total += (1 + down) * down / 2 + max(last_high, down + 1);
                    down = 0;
                }
            }
            else {
                down++;
                if (up) {
                    total += (1 + up) * up / 2 - 1;
                    last_high = up + 1;
                    up = 0;
                }
            }
        }
        if (up)
            total += (1 + up) * up / 2 + up;
        else if (down)
            total += (1 + down) * down / 2 + max(last_high, down + 1);
        else
            total++;
        return total;
    }
};
#endif //LEETCODE_N135_GREEDY_TODO_H
