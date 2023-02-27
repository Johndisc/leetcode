//
// Created by CGCL on 2023/2/27.
//

#ifndef LEETCODE_N211_TODO_TRIE_H
#define LEETCODE_N211_TODO_TRIE_H
#include "global.h"

class WordDictionary {
private:
	bool isEqual(string s1, string s2) {
		if (s1.size() != s2.size())
			return false;
		for (int i = 0; i < s1.size(); ++i) {
			if (s1[i] == '.')
				continue;
			else if (s1[i] != s2[i])
				return false;
		}
		return true;
	}
public:
	unordered_set<string> set;
	WordDictionary() {
	
	}
	
	void addWord(string word) {
		set.insert(word);
	}
	
	bool search(string word) {
		if (set.count(word))
			return true;
		for (auto s2: set) {
			if (isEqual(word,s2))
				return true;
		}
		return false;
	}
};
#endif //LEETCODE_N211_TODO_TRIE_H
