//
// Created by 58253 on 2023/1/17.
//

#ifndef LEETCODE_N150_H
#define LEETCODE_N150_H
#include "global.h"

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        for (auto s:tokens) {
            if (isdigit(s[0]) || isdigit(s[1]))
                stack.push(stoi(s));
            else {
                int b = stack.top();
                stack.pop();
                int a = stack.top();
                stack.pop();
                if (s == "+")
                    stack.push(a + b);
                else if (s == "-")
                    stack.push(a - b);
                else if (s == "*")
                    stack.push(a * b);
                else if (s == "/")
                    stack.push(a / b);
            }
        }
        return stack.top();
    }
};
#endif //LEETCODE_N150_H
