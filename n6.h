//
// Created by 58253 on 2022/6/10.
//
//20:38 - 21:01
#ifndef LEETCODE_Z_TRANSFORMATION_H
#define LEETCODE_Z_TRANSFORMATION_H

#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows==1)
            return s;
        string res = s;
        int index = 0, npos = 0;
        while (index < s.size()) {
            res[npos++] = s[index];
            index += 2 * (numRows - 1);
        }
        for (int i = 1; i < numRows - 1; ++i) {
            index = i;
            while (index < s.size()) {
                res[npos++] = s[index];
                index += 2 * (numRows - i - 1);
                if (index < s.size()) {
                    res[npos++] = s[index];
                    index += 2 * i;
                } else
                    break;
            }
        }
        index = numRows - 1;
        while (index < s.size()) {
            res[npos++] = s[index];
            index += 2 * (numRows - 1);
        }
        return res;
    }
};

#endif //LEETCODE_Z_TRANSFORMATION_H
