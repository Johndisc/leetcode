//
// Created by 58253 on 2022/6/18.
//

#ifndef LEETCODE_N34_H
#define LEETCODE_N34_H
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1, mid;
        vector<int> res;
        while (s <= e) {
            mid = (s + e) / 2;
            if (nums[mid] == target)
                break;
            if (nums[mid] > target)
                e = mid - 1;
            else if (nums[mid] < target)
                s = mid + 1;
        }
        if (s <= e) {
            cout << s << " " << mid << " " << e << endl;
//            5,5,6,8,8,9,9,10,10,10
            int se = e, es = s;
            if (s == 0 && nums[s] == target)
                res.push_back(0);
            else
                while (s <= se) {
                    if ((nums[mid - 1] != target && nums[mid] == target)) {
                        res.push_back(mid);
                        break;
                    }
                    if (nums[mid] == target)
                        se = mid - 1;
                    else
                        s = mid + 1;
                    mid = (s + se) / 2;
                }
            if (e == nums.size() - 1 && nums[e] == target)
                res.push_back(e);
            else
                while (es <= e) {
                    mid = (es + e) / 2;
                    if ((nums[mid + 1] != target && nums[mid] == target)) {
                        res.push_back(mid);
                        break;
                    }
                    if (nums[mid] == target)
                        es = mid + 1;
                    else
                        e = mid - 1;
                }
            return res;
        }
        else
            return vector<int>{-1, -1};
    }
};
#endif //LEETCODE_N34_H
