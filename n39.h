//
// Created by 58253 on 2022/6/21.
//

#ifndef LEETCODE_N39_H
#define LEETCODE_N39_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    unordered_map<int, set<vector<int>>> map;
    void findres(vector<int>& candidates, int target) {
        printf("find %d\n",target);
        for (int i = 0; i < candidates.size(); ++i) {
            if (candidates[i] > target)
                return;
            findres(candidates, target - candidates[i]);
            for (auto item: map[target - candidates[i]]) {
                item.push_back(candidates[i]);
                sort(item.begin(), item.end());
                map[target].insert(item);
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        for (int & candidate : candidates) {
            vector<int> tv;
            tv.push_back(candidate);
            map[candidate].insert(tv);
        }
        findres(candidates, target);
        for (const auto& item:map) {
            printf("%d : ", item.first);
            for (auto item1:item.second) {
                printf("[ ");
                for (auto item2:item1) {
                    printf("%d ", item2);
                }
                printf("]");
            }
            printf("\n");
        }
        vector<vector<int>> res;
        res.assign(map[target].begin(), map[target].end());
        return res;
    }
};
#endif //LEETCODE_N39_H
