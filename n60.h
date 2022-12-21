//
// Created by 58253 on 2022/12/21.
//

#ifndef LEETCODE_N60_H
#define LEETCODE_N60_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<char> bucket{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        int index[10];
        index[0] = 1;
        k--;
        for (int i = 0; i < n; ++i) {
            if (i > 0)
                index[i] = index[i - 1] * i;
        }
        string res;
        while (n > 1) {
            int cnt = k / index[n - 1];
            k = k % index[n - 1];
            res.append(1, bucket[cnt]);
            bucket.erase(bucket.begin() + cnt);
            n--;
        }
        res.append(1, bucket[0]);
        return res;
    }
};
#endif //LEETCODE_N60_H
