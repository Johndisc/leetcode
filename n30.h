//
// Created by 58253 on 2022/8/10.
//

#ifndef LEETCODE_N30_H
#define LEETCODE_N30_H

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
    vector<string> split(string s, int n) {
        vector<string> res;
        while (s.size() >= n) {
            res.push_back(s.substr(0, n));
            s = s.substr(n);
        }
        return res;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        int m = words.size();
        int n = words[0].size();
        vector<int> res;
        if (s.size() < m * n)
            return res;
        for (int i = 0; i < n; ++i) {
            unordered_map<string, int> hash;
            vector<string> splitS = split(s.substr(i), n);
            if (splitS.size() < m)
                return res;
            for (int j = 0; j < m; ++j)
                if (++hash[splitS[j]] == 0)
                    hash.erase(splitS[j]);
            for (int j = 0; j < m; ++j)
                if (--hash[words[j]] == 0)
                    hash.erase(words[j]);
            if (hash.empty())
                res.push_back(i);
            int head = 0;
            while (head + m < splitS.size()) {
                if (++hash[splitS[head + m]] == 0)
                    hash.erase(splitS[head + m]);
                if (--hash[splitS[head]] == 0)
                    hash.erase(splitS[head]);
                head++;
                if (hash.empty())
                    res.push_back(i + head * n);
            }
        }
        return res;
    }
};
#endif //LEETCODE_N30_H
