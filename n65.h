//
// Created by 58253 on 2022/8/17.
//

#ifndef LEETCODE_N65_H
#define LEETCODE_N65_H

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
    bool isInteger(string s) {
        if (s[0] == '+' || s[0] == '-')
            s.erase(0, 1);
        if (s.empty())
            return false;
        for (int i = 0; i < s.size(); ++i) {
            if (!(s[i] >= '0' && s[i] <= '9'))
                return false;
        }
        return true;
    }
    bool isSmall(string s) {
        if (s[0] == '+' || s[0] == '-')
            s.erase(0, 1);
        if (s.find('+') != string::npos || s.find('-') != string::npos || s.size() == 1)
            return false;

        int dpos = s.find('.');
        if (dpos == string::npos)
            return false;

        if (dpos > 0 && !isInteger(s.substr(0, dpos)))
            return false;
        for (int i = dpos + 1; i < s.size(); ++i) {
            if (!(s[i] >= '0' && s[i] <= '9'))
                return false;
        }
        return true;
    }

    bool isNumber(string s) {
        int epos = s.find('e');
        if (epos == string::npos)
            epos = s.find('E');
        if (epos != string ::npos && !isInteger(s.substr(epos + 1)))
            return false;
        if (epos != string::npos)
            s = s.substr(0, epos);
        return isInteger(s) || isSmall(s);
    }
};
#endif //LEETCODE_N65_H
