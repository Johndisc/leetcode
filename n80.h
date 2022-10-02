//
// Created by 58253 on 2022/8/8.
//

#ifndef LEETCODE_N80_H
#define LEETCODE_N80_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int head = 0, back = 0;
        int cnt = 0;
        int last = -10001;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != last) {
                cnt = 0;
                nums[back++] = nums[i];
            }
            else {
                cnt++;
                if (cnt < 2) {
                    nums[back++] = nums[i];
                }
            }
            last = nums[i];
        }
        return back;
    }
};
#endif //LEETCODE_N80_H
