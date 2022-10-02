//
// Created by 58253 on 2022/6/11.
//

#ifndef LEETCODE_N11_H
#define LEETCODE_N11_H
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int lh = height[0], rh = height[right];
        int ht = min(lh, rh);
        int area = ht * (right - left);
        while (left != right) {
            if (min(lh, rh) == lh) {
                while (height[left] <= min(lh, rh)) {
                    left++;
                    if (left == right)
                        return area;
                }
                lh = height[left];
                if (min(lh, rh) * (right - left) > area) {
                    ht = min(lh, rh);
                    area = ht * (right - left);
                }
            } else {
                while (height[right] <= min(lh, rh)) {
                    right--;
                    if (left == right)
                        return area;
                }
                rh = height[right];
                if (min(rh, lh) * (right - left) > area) {
                    ht = min(rh, lh);
                    area = ht * (right - left);
                }
            }
        }
        return area;
    }
};
#endif //LEETCODE_N11_H
