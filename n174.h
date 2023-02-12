//
// Created by CGCL on 2023/2/12.
//

#ifndef LEETCODE_N174_H
#define LEETCODE_N174_H
#include "global.h"

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        int dp[m][n];
        dp[m - 1][n - 1] = dungeon[m - 1][n - 1] >= 0 ? 1 : abs(dungeon[m - 1][n - 1]) + 1;
        for (int i = m - 2; i >= 0; --i) {
            if (dungeon[i][n - 1] > 0)
                dp[i][n - 1] = max(dp[i + 1][n - 1] - dungeon[i][n - 1], 1);
            else
                dp[i][n - 1] = dp[i + 1][n - 1] + abs(dungeon[i][n - 1]);
        }
        for (int i = n - 2; i >= 0; --i) {
            if (dungeon[m - 1][i] > 0)
                dp[m - 1][i] = max(dp[m - 1][i + 1] - dungeon[m - 1][i], 1);
            else
                dp[m - 1][i] = dp[m - 1][i + 1] + abs(dungeon[m - 1][i]);
        }
        for (int i = m - 2; i >= 0; --i) {
            for (int j = n - 2; j >= 0; --j) {
                if (dungeon[i][j] > 0)
                    dp[i][j] = max(min(dp[i][j + 1], dp[i + 1][j]) - dungeon[i][j], 1);
                else
                    dp[i][j] = min(dp[i][j + 1], dp[i + 1][j]) + abs(dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
};
#endif //LEETCODE_N174_H
