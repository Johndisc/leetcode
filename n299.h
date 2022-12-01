//
// Created by 58253 on 2022/10/17.
//

#ifndef LEETCODE_N299_H
#define LEETCODE_N299_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        unordered_map<char, int> map;
        vector<bool> bitmap(secret.size());
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                bitmap[i] = true;
                bulls++;
            }
            else {
                bitmap[i] = false;
                map[secret[i]]++;
            }
        }
        for (int i = 0; i < guess.size(); ++i) {
            if (bitmap[i])
                continue;
            if (map[guess[i]] > 0) {
                cows++;
                map[guess[i]]--;
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
#endif //LEETCODE_N299_H
