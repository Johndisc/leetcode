//
// Created by 58253 on 2022/12/1.
//

#ifndef LEETCODE_N381_H
#define LEETCODE_N381_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>
#include <ctime>

using namespace std;

class RandomizedCollection {
public:
    unordered_map<int, unordered_set<int>> table;
    vector<int> vt;
    RandomizedCollection() {
        srand((unsigned)time(NULL));
    }

    bool insert(int val) {
        bool res = true;
        if (table.count(val))
            res = false;
        table[val].insert(vt.size());
        vt.push_back(val);
        return res;
    }

    bool remove(int val) {
        if (!table.count(val))
            return false;
        int last = vt[vt.size() - 1];
        if (last == val) {
            table[last].erase(vt.size() - 1);
        }
        else {
            table[last].insert(*table[val].begin());
            table[last].erase(vt.size() - 1);
            vt[*table[val].begin()] = last;
            table[val].erase(*table[val].begin());
        }
        vt.pop_back();
        if (table[val].empty())
            table.erase(val);
        return true;
    }

    int getRandom() {
        int i = rand() % vt.size();
        return vt[i];
    }
    void print() {
        for (auto i:vt) {
            printf("%d ", i);
        }
        printf("\n");
        for (auto item: table) {
            printf("%d:", item.first);
            for (auto item1: item.second) {
                printf("%d ", item1);
            }
            printf("\n");
        }
    }
};
#endif //LEETCODE_N381_H
