#include "Aho-corasick.hpp"
Trie::Trie() {
	this->root = new TrieNode(nullptr, -1);
}


void Trie::insert(const string& key) {
	auto curr = root;
	for (char c : key) {
		if (curr->child[c - 'a'] == nullptr) {
			TrieNode* new_node = new TrieNode(curr, c);
			curr->child[c - 'a'] = new_node;
		}
		curr = curr->child[c - 'a'];
	}
	curr->end_word = true;
}

bool Trie::search(const string& key) {
	auto curr = root;
	for (char c : key) {
		if (curr->child[c - 'a'] == nullptr) {
			return false;
		}
		curr = curr->child[c - 'a'];
	}
	return curr->end_word;
}

TrieNode * Trie::get_link(TrieNode* node) {
	if (node->p_suff == nullptr) {

		if (node == root || node->p_parrent == root) {
			node->p_suff = root;
		}

		else {
			node->p_suff = go(get_link(node->p_parrent), node->symb);
		}
	}
	return node->p_suff;
}

TrieNode* Trie::go(TrieNode* node, int symb) {
	if (node->p_go[symb - 'a'] == nullptr) {

		if (node->child[symb - 'a'] != nullptr) {
			node->p_go[symb - 'a'] = node->child[symb - 'a'];
		}

		else if (node == root) {
			node->p_go[symb - 'a'] = root;
		}

		else {
			node->p_go[symb - 'a'] = go(get_link(node), symb);
		}

	}
	return node->p_go[symb - 'a'];
}

int Trie::find_substr(const string& str, const string& substr){
	this->insert(substr);
	auto curr = root;
	for (int i = 0; i < str.size(); i++) {
		curr = go(curr, str[i]);
		if (curr->end_word) {
			return i - substr.size() + 1;
		}
	}
	return -1;
}