//
// Created by 58253 on 2022/8/9.
//

#ifndef LEETCODE_N20_H
#define LEETCODE_N20_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (char &c: s) {
            if (c == '(' || c == '[' || c == '{')
                stack.push(c);
            else if (c == ')') {
                if (!stack.empty() && stack.top() == '(')
                    stack.pop();
                else
                    return false;
            }
            else if (c == ']') {
                if (!stack.empty() && stack.top() == '[')
                    stack.pop();
                else
                    return false;
            }
            else if (c == '}') {
                if (!stack.empty() && stack.top() == '{')
                    stack.pop();
                else
                    return false;
            }
        }
        if(stack.empty())
            return true;
        else
            return false;
    }
};
#endif //LEETCODE_N20_H
