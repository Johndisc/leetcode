//
// Created by 58253 on 2023/1/20.
//

#ifndef LEETCODE_N155_H
#define LEETCODE_N155_H
#include "global.h"

class MinStack {
public:
    stack<int> istack;
    map<int, int> imap;

    MinStack() {

    }

    void push(int val) {
        istack.push(val);
        imap[val]++;
    }

    void pop() {
        if (!istack.empty()) {
            imap[istack.top()]--;
            if (!imap[istack.top()])
                imap.erase(istack.top());
            istack.pop();
        }
    }

    int top() {
        return istack.top();
    }

    int getMin() {
        return (*imap.begin()).first;
    }
};
#endif //LEETCODE_N155_H
