//
// Created by 58253 on 2022/9/13.
//

#ifndef LEETCODE_N179_H
#define LEETCODE_N179_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    static bool compare(const string &s1,const string &s2) {
        int i = 0;
        while (i < s1.size() && i < s2.size()) {
            if (s1[i] > s2[i])
                return true;
            else if (s1[i] < s2[i])
                return false;
            else
                i++;
        }
        if (i == s1.size() && i == s2.size())
            return true;
        else if (i == s1.size())
            return compare(s1, s2.substr(s1.size()));
        else
            return compare(s1.substr(s2.size()), s2);
    }
    string largestNumber(vector<int>& nums) {
        bool is_zero = true;
        for (auto & i : nums) {
            if (i != 0) {
                is_zero = false;
                break;
            }
        }
        if (is_zero)
            return "0";
        vector<string> snum(nums.size());
        for (int i = 0; i < nums.size(); ++i)
            snum[i] = to_string(nums[i]);
        sort(snum.begin(), snum.end(), compare);
        string ans;
        for (auto & i : snum) {
            ans += i;
        }
        return ans;
    }
};
#endif //LEETCODE_N179_H
