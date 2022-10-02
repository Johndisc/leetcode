//
// Created by 58253 on 2022/8/19.
//

#ifndef LEETCODE_N126_SSSP_H
#define LEETCODE_N126_SSSP_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <stack>
#include <map>

using namespace std;
class Solution {
public:
    vector<vector<string>> res;
    bool isClose(string &s1, string &s2) {
        int diff = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                diff++;
                if (diff > 1)
                    return false;
            }
        }
        if (diff == 1)
            return true;
        else
            return false;
    }

    void findRes(vector<string> &wordList, vector<set<int>> &next_node, vector<int> path, int i, string &beginWord) {
        if (next_node[i].empty()) {
            vector<string> sp;
            sp.push_back(beginWord);
            for (auto item: path)
                sp.push_back(wordList[item]);
            res.push_back(sp);
            return;
        }
        for (int next:next_node[i]) {
            path.push_back(next);
            findRes(wordList, next_node, path, next, beginWord);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // dp[i]表示第i个词到endWord的距离
        vector<set<int>> next_node(wordList.size());
        vector<int> dp(wordList.size(), -1);
        bool isIn = false;
        for (int i = 0; i < wordList.size(); ++i) {
            if (wordList[i] == endWord) {
                isIn = true;
                dp[i] = 0;
            }
        }
        if (!isIn)
            return res;
        bool next_round = true;
        while (next_round) {
            next_round = false;
            for (int i = 0; i < wordList.size(); ++i) {
                if (dp[i] != -1) {
                    for (int j = 0; j < wordList.size(); ++j) {
                        if (j != i && isClose(wordList[i], wordList[j])) {
                            if (dp[j] == -1 || dp[i] + 1 < dp[j]) {
                                dp[j] = dp[i] + 1;
                                next_node[j].clear();
                                next_node[j].insert(i);
                                next_round = true;
                            } else if (dp[i] + 1 == dp[j] && next_node[j].find(i) == next_node[j].end()) {
                                next_node[j].insert(i);
                                next_round = true;
                            }
                        }
                    }
                }
            }
        }
        set<int> first;
        int mindist = INT_MAX;
        for (int i = 0; i < wordList.size(); ++i) {
//            cout << wordList[i] << " ";
//            printf("%d %d : ", i, dp[i]);
//            for (int j: next_node[i])
//                printf("%d ", j);
//            printf("\n");
            if (isClose(beginWord, wordList[i])) {
                if (dp[i] < mindist) {
                    mindist = dp[i];
                    first.clear();
                    first.insert(i);
                }
                else if (dp[i] == mindist)
                    first.insert(i);
            }
        }
        for (int i: first) {
//            cout << i << endl;
            vector<int> path;
            path.push_back(i);
            findRes(wordList, next_node, path, i, beginWord);
        }
        return res;
    }
};
#endif //LEETCODE_N126_SSSP_H
