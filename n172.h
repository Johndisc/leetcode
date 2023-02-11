//
// Created by CGCL on 2023/2/11.
//

#ifndef LEETCODE_N172_H
#define LEETCODE_N172_H
#include "global.h"

class Solution {
public:
    int trailingZeroes(int n) {
        return n / 5 + n / 25 + n / 125 + n / 625 + n / 3125;
    }
};
#endif //LEETCODE_N172_H
