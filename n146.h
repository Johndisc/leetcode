//
// Created by 58253 on 2022/9/20.
//

#ifndef LEETCODE_N146_H
#define LEETCODE_N146_H

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

// 使用伪头部和伪尾部节点
class LRUCache {
public:
    struct Node {
        int next;
        int pre;
    };
    unordered_map<int, int> cache;
    unordered_map<int, Node> node_list;
    int size;
    int new_key;
    int old_key;

    LRUCache(int capacity) {
        size = capacity;
        new_key = -1;
        node_list[-1].next = -2;
        node_list[-2].pre = -1;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            node_list[node_list[key].pre].next = node_list[key].next;
            node_list[node_list[key].next].pre = node_list[key].pre;
            new_key = node_list[-2].pre;
            node_list[key].next = -2;
            node_list[key].pre = new_key;
            node_list[new_key].next = key;
            node_list[-2].pre = key;
            new_key = key;
            return cache[key];
        }
        else
            return -1;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            node_list[node_list[key].pre].next = node_list[key].next;
            node_list[node_list[key].next].pre = node_list[key].pre;
            new_key = node_list[-2].pre;
            node_list[key].next = -2;
            node_list[key].pre = new_key;
            node_list[new_key].next = key;
            node_list[-2].pre = key;
            new_key = key;
        }
        else {
            if (size == cache.size()) {
                cache.erase(node_list[-1].next);
                node_list[node_list[node_list[-1].next].next].pre = -1;
                node_list[-1].next = node_list[node_list[-1].next].next;
                new_key = node_list[-2].pre;
                node_list[key].next = -2;
                node_list[key].pre = new_key;
                node_list[new_key].next = key;
                node_list[-2].pre = key;
                new_key = key;
            }
            else {
                new_key = node_list[-2].pre;
                node_list[key].next = -2;
                node_list[key].pre = new_key;
                node_list[new_key].next = key;
                node_list[-2].pre = key;
                new_key = key;
            }
        }
        cache[key] = value;
    }
};
#endif //LEETCODE_N146_H
