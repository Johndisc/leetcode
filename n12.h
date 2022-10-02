//
// Created by 58253 on 2022/8/8.
//

#ifndef LEETCODE_N12_H
#define LEETCODE_N12_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string res;
        int cnt = num / 1000;
        res += string(cnt, 'M');
        num %= 1000;
        if (num/100 == 9) {
            res += "CM";
            num %= 100;
        }
        else if (num >= 500) {
            res += "D";
            num -= 500;
        }
        else if (num/100 == 4) {
            res += "CD";
            num %= 100;
        }
        cnt = num / 100;
        res += string(cnt, 'C');
        num %= 100;

        if (num/10 == 9) {
            res += "XC";
            num %= 10;
        }
        else if (num >= 50) {
            res += "L";
            num -= 50;
        }
        else if (num/10 == 4) {
            res += "XL";
            num %= 10;
        }
        cnt = num / 10;
        res += string(cnt, 'X');
        num %= 10;

        if (num == 9) {
            res += "IX";
            return res;
        }
        else if (num >= 5) {
            res += "V";
            num -= 5;
        }
        else if (num == 4) {
            res += "IV";
            return res;
        }
        cnt = num;
        res += string(cnt, 'I');
        return res;
    }
};
#endif //LEETCODE_N12_H
