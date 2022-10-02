//
// Created by 58253 on 2022/8/17.
//

#ifndef LEETCODE_N71_H
#define LEETCODE_N71_H
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
    string simplifyPath(string path) {
        int pos = 0;
        char last = ' ';
        // 去除//
        for (int i = 0; i < path.size(); ++i) {
            if (path[i] == '/' && last == '/') {
                path.erase(i, 1);
                i--;
            }
            else
                last = path[i];
        }
        pos = -2;
        while ((pos = path.find("./", pos + 2)) != -1) {
            if (path[pos - 1] == '/') {
                path.erase(pos, 2);
                pos -= 2;
            }
        }
        pos = -3;
        while ((pos = path.find("../", pos + 3)) != -1) {
            if (path[pos - 1] == '/') {
                int cnt = 0;
                if (pos == 1)
                    path.erase(pos, 3);
                else {
                    while (path[pos - 2 - cnt] != '/')
                        cnt++;
                    path.erase(pos - 1 - cnt, cnt + 4);
                }
                pos = pos - 4 - cnt;
            }
        }
        if ((pos = path.find("/.")) != -1 && pos == path.size() - 2)
            path.erase(pos + 1, 1);
        if ((pos = path.find("/..")) != -1 && pos == path.size() - 3) {
            if (pos == 0)
                return "/";
            int cnt = 0;
            while (path[pos - 1 - cnt] != '/')
                cnt++;
            path.erase(pos - cnt, cnt + 3);
        }
        if (path.size() != 1&&path[path.size() - 1] == '/')
            path.erase(path.size() - 1, 1);
        return path;
    }
};
#endif //LEETCODE_N71_H
