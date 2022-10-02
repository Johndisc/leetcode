//
// Created by 58253 on 2022/6/19.
//
// 没过
#ifndef LEETCODE_N4_H
#define LEETCODE_N4_H
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int mid = (nums1.size() + nums2.size()) / 2 - 1, res;
        int s1 = 0, e1 = nums1.size() - 1, s2 = 0, e2 = nums2.size() - 1;
        int op = 1;
        while (e1 + e2 != mid) {
            if (op == 1) {
                int mid1 = (s1 + e1) / 2;
                if (nums1[mid1] > nums2[e2]) {
                    if (mid1 + e2 == mid) {
                        if ((nums1.size() + nums2.size()) / 2)
                            return nums1[mid1];
                        else
                            return ((double) (nums2[e2] + nums1[mid1]) / 2);
                    }
                    else if (mid1 + e2 > mid)
                        e1 = mid1;
                    else
                        s1 = mid1;
                } else {
                    if (mid1 + e2 == mid) {
                        if ((nums1.size() + nums2.size()) / 2)
                            return nums2[e2];
                        else
                            return ((double) (nums2[e2] + nums1[mid1]) / 2);
                    }
                    else if (mid1 + e2 > mid) {
                        op = 2;
                        e1 = mid1;
                    }
                    else
                        s1 = mid1;
                }
            } else {
                int mid2 = (s2 + e2) / 2;
                if (nums2[mid2] > nums1[e1]) {
                    if (mid2 + e1 == mid) {
                        if ((nums1.size() + nums2.size()) / 2)
                            return nums2[mid2];
                        else
                            return ((double) (nums1[e1] + nums2[mid2]) / 2);
                    }
                    else if (mid2 + e1 > mid)
                        e2 = mid2;
                    else
                        s2 = mid2;
                } else {
                    if (mid2 + e1 == mid) {
                        if ((nums1.size() + nums2.size()) / 2)
                            return nums1[e1];
                        else
                            return ((double) (nums1[e1] + nums2[mid2]) / 2);
                    }
                    if (mid2 + e1 > mid) {
                        op = 1;
                        e2 = mid2;
                    }
                    else
                        s2 = mid2;
                }
            }
        }
        cout << e1 << " " << e2 << endl;
        if ((nums1.size() + nums2.size()) % 2)
            return max(nums1[e1], nums2[e2]);
        else {
            int a;
            if (e1 = nums1.size() - 1)
                a = nums2[e2 + 1];
            else if (e2 = nums2.size() - 1)
                a = nums1[e1 + 1];
            else
                a = min(nums1[e1 + 1], nums2[e2 + 1]);
            return ((double(max(nums1[e1], nums2[e2]) + a)) / 2);
        }
    }
};
#endif //LEETCODE_N4_H
