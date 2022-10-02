//
// Created by 58253 on 2022/9/1.
//

#ifndef LEETCODE_N165_H
#define LEETCODE_N165_H
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
    int compare(string s1, string s2) {
        if (s1.empty())
            s1 = "0";
        if (s2.empty())
            s2 = "0";
        int i = 0, j = 0;
        while (i < s1.size() - 1 && s1[i] == '0')
            i++;
        while (j < s2.size() - 1 && s2[j] == '0')
            j++;
        if (s1.size() - i > s2.size() - j)
            return 1;
        else if (s1.size() - i < s2.size() - j)
            return -1;
        while (i < s1.size()) {
            if (s1[i] > s2[j])
                return 1;
            else if (s1[i] < s2[j])
                return -1;
            else {
                i++;
                j++;
            }
        }
        return 0;
    }

    int compareVersion(string version1, string version2) {
        int po1 = 0, po2 = 0;
        while (!version1.empty() || !version2.empty()) {
            po1 = version1.find('.');
            po2 = version2.find('.');
            string s1, s2;
            s1 = po1 == -1 ? version1 : version1.substr(0, po1);
            s2 = po2 == -1 ? version2 : version2.substr(0, po2);
            int comp = compare(s1, s2);
            if (comp != 0)
                return comp;

            if (po1 != -1)
                version1.erase(0, po1 + 1);
            else
                version1.clear();
            if (po2 != -1)
                version2.erase(0, po2 + 1);
            else
                version2.clear();
        }
        return 0;
    }
};
#endif //LEETCODE_N165_H
