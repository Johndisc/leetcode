//
// Created by 58253 on 2022/8/22.
//

#ifndef LEETCODE_N151_H
#define LEETCODE_N151_H
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
    string reverseWords(string s) {
        stack<string> sentence;
        string word;
        for (char i : s) {
            if (i == ' ') {
                if (!word.empty()) {
                    sentence.push(word);
                    word.clear();
                }
            }
            else
                word.append(1, i);
        }
        if (!word.empty())
            sentence.push(word);

        word = sentence.top();
        sentence.pop();
        while (!sentence.empty()) {
            word += " " + sentence.top();
            sentence.pop();
        }
        return word;
    }
};
#endif //LEETCODE_N151_H
