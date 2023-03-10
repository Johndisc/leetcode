//
// Created by 58253 on 2023/3/5.
//

#ifndef LEETCODE_N223_H
#define LEETCODE_N223_H
#include "global.h"

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = (ax2 - ax1) * (ay2 - ay1);
        int area2 = (bx2 - bx1) * (by2 - by1);
        if (ay1 >= by2 || by1 >= ay2 || bx1 >= ax2 || ax1 >= bx2)
            return area1 + area2;
        int dist1 = min(min(abs(by2 - ay1), abs(ay2 - by1)), min(ay2 - ay1, by2 - by1));
        int dist2 = min(min(abs(bx2 - ax1), abs(ax2 - bx1)), min(ax2 - ax1, bx2 - bx1));
        return area1 + area2 - dist1 * dist2;
    }
};
#endif //LEETCODE_N223_H
