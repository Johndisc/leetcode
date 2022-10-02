//
// Created by 58253 on 2022/7/8.
//

#ifndef LEETCODE_N63_H
#define LEETCODE_N63_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;
class Solution {
public:
    int findRes(vector<vector<int>> &cnt, vector<vector<int>>& obstacleGrid,int i,int j) {
        if (i == obstacleGrid.size() - 1 && j == obstacleGrid[0].size() - 1)
            return 1;
        if (cnt[i][j] != -1)
            return cnt[i][j];
        cnt[i][j] = 0;
        if (i < obstacleGrid.size() - 1 && obstacleGrid[i + 1][j] != 1)
            cnt[i][j] += findRes(cnt, obstacleGrid, i + 1, j);
        if (j < obstacleGrid[0].size() - 1 && obstacleGrid[i][j + 1] != 1) {
            cnt[i][j] += findRes(cnt, obstacleGrid, i, j + 1);
        }
        return cnt[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> cnt(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        if (obstacleGrid[0][0] == 1)
            return 0;
        return findRes(cnt, obstacleGrid, 0, 0);
    }
};
#endif //LEETCODE_N63_H
