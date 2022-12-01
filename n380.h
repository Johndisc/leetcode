//
// Created by 58253 on 2022/12/1.
//

#ifndef LEETCODE_N380_H
#define LEETCODE_N380_H

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

class RandomizedSet {
public:
    unordered_map<int, int> table;
    vector<int> vt;
    RandomizedSet() {

    }

    bool insert(int val) {
        if (table.count(val))
            return false;
        table[val] = vt.size();
        vt.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (!table.count(val))
            return false;
        table[vt[vt.size() - 1]] = table[val];
        vt[table[val]] = vt[vt.size() - 1];
        vt.pop_back();
        table.erase(val);
        return true;
    }

    int getRandom() {
        int i = rand() % vt.size();
        return vt[i];
    }
};
#endif //LEETCODE_N380_H
