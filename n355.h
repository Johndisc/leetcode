//
// Created by 58253 on 2022/12/1.
//

#ifndef LEETCODE_N355_H
#define LEETCODE_N355_H

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

class Twitter {
public:
    unordered_map<int, unordered_set<int>> follows;
    vector<pair<int, int>> tweets;

    Twitter() {

    }

    void postTweet(int userId, int tweetId) {
        tweets.emplace_back(userId, tweetId);
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        int cnt = 0;
        for (auto it = tweets.rbegin(); it != tweets.rend(); it++) {
            if (it->first == userId || follows[userId].count(it->first)) {
                res.push_back(it->second);
                cnt++;
            }
            if (cnt == 10)
                break;
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};
#endif //LEETCODE_N355_H
