//
// Created by 58253 on 2022/8/6.
//

#ifndef LEETCODE_N68_H
#define LEETCODE_N68_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    string sealString(vector<string> &words, int maxWidth, int begin, int end, int words_len) {
        int blank = maxWidth - words_len;
        int pos = end - begin - 1;
        string s1;
        for (int i = begin; i < end - 1; ++i) {
            s1 += words[i];
            s1 += string((blank + pos - 1) / pos, ' ');
            blank -= (blank + pos - 1) / pos;
            pos--;
        }
        s1 += words[end - 1];
        if (s1.length() < maxWidth)
            s1 += string(maxWidth - s1.length(), ' ');
        return s1;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int begin = 0, current_len = 0, words_len = 0;
        for (int i = 0; i < words.size(); ++i) {
            if (current_len == 0) {
                begin = i;
                current_len = words[i].size();
                words_len = current_len;
            } else if (current_len + words[i].length() + 1 <= maxWidth) {
                current_len += words[i].length() + 1;
                words_len += words[i].length();
            } else {
                res.push_back(sealString(words, maxWidth, begin, i, words_len));
                i--;
                current_len = 0;
                words_len = 0;
            }
        }
        string last;
        for (int i = begin; i < words.size() - 1; ++i) {
            last += words[i] + " ";
        }
        last += *(words.end() - 1);
        last += string(maxWidth - last.size(), ' ');
        res.push_back(last);
        return res;
    }
};
#endif //LEETCODE_N68_H
