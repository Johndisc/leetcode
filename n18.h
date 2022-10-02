//
// Created by 58253 on 2022/6/13.
//

#ifndef LEETCODE_N18_H
#define LEETCODE_N18_H
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
//        for (auto item:nums) {
//            cout << item << " ";
//        }
//        cout << endl;
        long a, b, c, d;
        long sum;
        vector<vector<int>> vres;
        if (nums.size() < 4)
            return vres;
        for (int i = 0; i < nums.size() - 3; ++i) {
            while (i > 0 && nums[i] == nums[i - 1])
                i++;
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                while (j > i + 1 && nums[j] == nums[j - 1])
                    j++;
                c = j + 1;
                d = nums.size() - 1;
                while (c < d) {
                    sum = nums[i] + nums[j] + nums[c] + nums[d];
                    if (sum == target) {
//                        cout << i << " " << j << " " << c << " " << d << endl;
                        vres.push_back(vector<int>{nums[i], nums[j], nums[c], nums[d]});
                        c++;
                        d--;
                        while (d > c && nums[c] == nums[c - 1])
                            c++;
                        while (d > c && nums[d] == nums[d + 1])
                            d--;
                    }
                    else if (sum < target)
                        c++;
                    else
                        d--;
                }
            }

        }
        return vres;
    }
};
#endif //LEETCODE_N18_H
