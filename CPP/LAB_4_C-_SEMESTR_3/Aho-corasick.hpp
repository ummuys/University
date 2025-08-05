#pragma once
#include <iostream>
#define ALPH 26
//ENG_ALPH 26
//RUS_ALPH 33
using namespace std;

struct TrieNode{
	TrieNode * child[ALPH];
	TrieNode* p_go[ALPH];
	TrieNode* p_suff;
	TrieNode* p_parrent;
	int symb;
	bool end_word;
	TrieNode(TrieNode* pp, int sb) {
		p_suff = nullptr;
		p_parrent = pp;
		symb = sb;
		end_word = false;
		for (int i = 0; i < ALPH; i++) { 
			child[i] = nullptr;
			p_go[i] = nullptr;
		}
	}
};

class Trie{
private:
	TrieNode* root;
	TrieNode* get_link(TrieNode* node);
	TrieNode* go(TrieNode* node, int symb);
public:
	Trie();
	void insert(const string& key);
	bool search(const string& key);
	void erase(const string& key);
	int find_substr(const string& str, const string& substr);
};