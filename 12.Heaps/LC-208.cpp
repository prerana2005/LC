#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
    struct trieNode {
        bool isendofword;
        trieNode* children[26];
    };

    trieNode* getnode() {
        trieNode* newnode = new trieNode();
        newnode->isendofword = false;
        for (int i = 0; i < 26; i++) {
            newnode->children[i] = NULL;
        }
        return newnode;
    }

    trieNode* root;

    Trie() {
        root = getnode();
    }

    void insert(string word) {
        trieNode* crawler = root;

        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            int idx = ch - 'a';

            if (crawler->children[idx] == NULL) {
                crawler->children[idx] = getnode();
            }
            crawler = crawler->children[idx];
        }
        crawler->isendofword = true;
    }

    bool search(string word) {
        trieNode* crawler = root;

        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            int idx = ch - 'a';

            if (crawler->children[idx] == NULL) {
                return false;
            }
            crawler = crawler->children[idx];
        }

        // ✅ FIX: should return true if end of word is marked
        return (crawler != NULL && crawler->isendofword == true);
    }

    bool startsWith(string prefix) {
        trieNode* crawler = root;

        for (int i = 0; i < prefix.length(); i++) {
            char ch = prefix[i];
            int idx = ch - 'a';

            if (crawler->children[idx] == NULL) {
                return false;
            }
            crawler = crawler->children[idx];
        }

        // ✅ If we finished iterating the prefix, it exists
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
