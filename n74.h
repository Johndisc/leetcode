//
// Created by 58253 on 2022/8/6.
//

#ifndef LEETCODE_N74_H
#define LEETCODE_N74_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;
class Solution {
public:
    bool findInRow(vector<int> &row,int target) {
        int n = row.size();
        int s = 0, e = n - 1, mid;
        while (s <= e) {
            mid = (s + e) / 2;
            if (row[mid] == target)
                return true;
            else if (row[mid] > target)
                e = mid - 1;
            else
                s = mid + 1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int s = 0, e = m - 1, mid;
        while (s <= e) {
            mid = (s + e) / 2;
            if (matrix[mid][0] <= target && (mid == m - 1 || matrix[mid + 1][0] > target))
                return findInRow(matrix[mid], target);
            else if (matrix[mid][0] > target)
                e = mid - 1;
            else if (matrix[mid + 1][0] <= target)
                s = mid + 1;
        }
        return false;
    }
};
#endif //LEETCODE_N74_H
