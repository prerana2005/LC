class Solution {
public:
    // Define Trie Node structure
    struct TrieNode {
        map<char, TrieNode*> children;
        vector<string> suggestions;  // up to 3 lexicographically smallest words
    };
    
    // Root node of Trie
    TrieNode* root = new TrieNode();
    
    // Function to insert a word into the Trie
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            // create new node if doesn't exist
            if (!node->children[c]) node->children[c] = new TrieNode();
            node = node->children[c];
            
            // insert the word into this node's suggestion list
            node->suggestions.push_back(word);
            
            // keep suggestions sorted and trimmed to top 3
            sort(node->suggestions.begin(), node->suggestions.end());
            if (node->suggestions.size() > 3)
                node->suggestions.pop_back();
        }
    }

    // Main function for problem
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        // Step 1: Sort lexicographically
        sort(products.begin(), products.end());
        
        // Step 2: Build Trie
        for (string &p : products)
            insert(p);
        
        // Step 3: Get suggestions for each prefix
        vector<vector<string>> result;
        TrieNode* node = root;
        for (char c : searchWord) {
            if (node && node->children.count(c)) {
                node = node->children[c];
                result.push_back(node->suggestions);
            } else {
                node = nullptr;
                result.push_back({});
            }
        }
        return result;
    }
};
