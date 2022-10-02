//
// Created by 58253 on 2022/6/25.
//

#ifndef LEETCODE_N40_H
#define LEETCODE_N40_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    void findans(vector<int>& candidates, vector<int> &container, int total, int idx)
    {
        if (total == 0) {
            ans.emplace_back(container);
            return;
        }
        if (idx == candidates.size())
            return;
        int last = -1;
        for (int i = idx; i < candidates.size(); ++i) {
            if (total >= candidates[i]) {
                if (candidates[i] == last)
                    continue;
                last = candidates[i];
                container.push_back(candidates[i]);
                findans(candidates, container, total - candidates[i], i + 1);
                container.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> container;
        sort(candidates.begin(), candidates.end());
        findans(candidates, container, target, 0);
        return ans;
    }
};
#endif //LEETCODE_N40_H
