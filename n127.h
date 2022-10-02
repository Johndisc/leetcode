//
// Created by 58253 on 2022/8/19.
//

#ifndef LEETCODE_N127_H
#define LEETCODE_N127_H
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

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int wlen = wordList.size() + 1;
        int endpos = -1;
        vector<vector<bool>> adj(wlen, vector<bool>(wlen, false));
        for (int i = 0; i < wordList.size(); ++i) {
            if (wordList[i] == endWord)
                endpos = i + 1;
            if (isClose(beginWord, wordList[i])) {
                adj[0][i + 1] = true;
                adj[i + 1][0] = true;
            }
        }
        if (endpos == -1)
            return 0;
        for (int i = 0; i < wordList.size(); ++i) {
            for (int j = i + 1; j < wordList.size(); ++j) {
                if (!adj[i + 1][j + 1] && isClose(wordList[i], wordList[j])) {
                    adj[i + 1][j + 1] = true;
                    adj[j + 1][i + 1] = true;
                }
            }
        }
        vector<int> dist(wlen, INT_MAX);
        dist[0] = 0;
        vector<bool> active(wlen, false);
        vector<bool> next(wlen, false);
        active[0] = true;
        bool finished = false;
        while (!finished) {
            finished = true;
            for (int i = 0; i < wlen; ++i) {
                if (active[i]) {
                    for (int j = 0; j < wlen; ++j) {
                        if (adj[i][j] && dist[j] > dist[i] + 1) {
                            dist[j] = dist[i] + 1;
                            finished = false;
                            next[j] = true;
                        }
                    }
                    active[i] = false;
                }
            }
            active = next;
            next.assign(wlen, false);
        }
//        for (int i:dist) {
//            printf("%d ", i);
//        }
//        printf("\n");
        if (dist[endpos] == INT_MAX)
            return 0;
        return dist[endpos] + 1;
    }
};
#endif //LEETCODE_N127_H
