//
// Created by 58253 on 2022/8/9.
//

#ifndef LEETCODE_N13_H
#define LEETCODE_N13_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int i = s.size() - 1;
        char last = ' ';
        int ones = 0, sum = 0;
        while (i >= 0) {
            if (s[i] == 'I') {
                ones++;
                last = 'I';
            }
            else if (s[i] == 'V') {
                sum += ones;
                if (i > 0 && s[i - 1] == 'I') {
                    sum += 4;
                    i--;
                }
                else
                    sum += 5;
                ones = 0;
                last = 'V';
            }
            else if (s[i] == 'X') {
                if (last == 'I') {
                    sum += ones;
                    ones = 0;
                }
                if (i > 0 && s[i - 1] == 'I') {
                    sum += 9;
                    i--;
                }
                else
                    ones++;
                last = 'X';
            }
            else if (s[i] == 'L') {
                if (last == 'I')
                    sum += ones;
                else if (last == 'X')
                    sum += ones * 10;
                if (i > 0 && s[i - 1] == 'X') {
                    sum += 40;
                    i--;
                }
                else
                    sum += 50;
                ones = 0;
                last = 'L';
            }
            else if (s[i] == 'C') {
                if (last == 'I') {
                    sum += ones;
                    ones = 0;
                }
                else if (last == 'X') {
                    sum += ones * 10;
                    ones = 0;
                }
                if (i > 0 && s[i - 1] == 'X') {
                    sum += 90;
                    i--;
                }
                else
                    ones++;
                last = 'C';
            }
            else if (s[i] == 'D') {
                if (last == 'I')
                    sum += ones;
                else if (last == 'X')
                    sum += ones * 10;
                else if (last == 'C')
                    sum += ones * 100;
                if (i > 0 && s[i - 1] == 'C') {
                    sum += 400;
                    i--;
                }
                else
                    sum += 500;
                ones = 0;
                last = 'D';
            }
            else if (s[i] == 'M') {
                if (last == 'I') {
                    sum += ones;
                    ones = 0;
                }
                else if (last == 'X') {
                    sum += ones * 10;
                    ones = 0;
                }
                else if (last == 'C') {
                    sum += ones * 100;
                    ones = 0;
                }
                if (i > 0 && s[i - 1] == 'C') {
                    sum += 900;
                    i--;
                }
                else
                    ones++;
                last = 'M';
            }
            i--;
        }
        if (s[0] == 'I')
            sum += ones;
        else if (s[0] == 'X')
            sum += ones * 10;
        else if (s[0] == 'C')
            sum += ones * 100;
        else if (s[0] == 'M')
            sum += ones * 1000;
        return sum;
    }
};
#endif //LEETCODE_N13_H
