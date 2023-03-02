//
// Created by CGCL on 2023/2/27.
//

#ifndef LEETCODE_N211_TRIE_H
#define LEETCODE_N211_TRIE_H
#include "global.h"

class WordDictionary {
private:
	struct TrieNode {
		TrieNode *children[26];
		bool isEnd;
		TrieNode(){
			for (auto & i : children) {
				i = nullptr;
				isEnd = false;
			}
		}
	};
	
	bool searchSub(TrieNode *node, string word) {
		if (word.empty())
			return node->isEnd;
		for (int i = 0; i < word.size(); ++i){
			char c = word[i];
			if (c == '.') {
				for (int j = 0; j < 26; ++j) {
					if (node->children[j] && searchSub(node->children[j], word.substr(i + 1)))
						return true;
				}
				return false;
			}
			else if (node->children[c - 'a'])
				node = node->children[c - 'a'];
			else
				return false;
		}
		return node->isEnd;
	}
	
public:
	TrieNode *root;
	WordDictionary() {
		root = new TrieNode;
	}
	
	void addWord(string word) {
		TrieNode *node = root;
		for (char &c: word) {
			if (node->children[c - 'a'])
				node = node->children[c - 'a'];
			else {
				node->children[c - 'a'] = new TrieNode;
				node = node->children[c - 'a'];
			}
		}
		node->isEnd = true;
	}
	
	bool search(string word) {
		TrieNode *node = root;
		return searchSub(node, word);
	}
};
#endif //LEETCODE_N211_TRIE_H
