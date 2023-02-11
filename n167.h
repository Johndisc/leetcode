//
// Created by CGCL on 2023/2/11.
//

#ifndef LEETCODE_N167_H
#define LEETCODE_N167_H
#include "global.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int s = 0, e = numbers.size() - 1;
        while (s < e) {
            int sum = numbers[s] + numbers[e];
            if (sum == target)
                break;
            else if (sum > target)
                e--;
            else
                s++;
        }
        return {s + 1, e + 1};
    }
};
#endif //LEETCODE_N167_H
