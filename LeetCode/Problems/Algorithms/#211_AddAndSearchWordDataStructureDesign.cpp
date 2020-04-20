class TrieNode{
public:
    static const int ALPHABET_SIZE = 26;
    static const char FIRST_LETTER = 'a';
    bool is_terminal_node;
    vector<TrieNode*> children;
    
    TrieNode(bool is_terminal_node = false){
        this->is_terminal_node = is_terminal_node;
        this->children.resize(ALPHABET_SIZE, NULL);
    }
    
    void insert(const string& word){
        TrieNode* node = this;
        for(char c: word){
            int edge_id = c - FIRST_LETTER;
            if(node->children[edge_id] == NULL){
                node->children[edge_id] = new TrieNode();
            }
            node = node->children[edge_id];
        }
        node->is_terminal_node = true;
    }
    
    void search(TrieNode* node, const string& word, int pos, bool& found){
        if(pos == word.length()){
            found = found || (node != NULL && node->is_terminal_node);
        }else if(node != NULL){
            char first_char = word[pos];
            char last_char = word[pos];
            if(word[pos] == '.'){
                first_char = FIRST_LETTER;
                last_char = FIRST_LETTER + ALPHABET_SIZE - 1;
            }
            for(char c = first_char; !found && c <= last_char; ++c){
                int edge_id = c - FIRST_LETTER;
                if(node->children[edge_id] != NULL){
                    search(node->children[edge_id], word, pos + 1, found);
                }
            }
        }
    }
    
    bool contains(const string& word, int pos = 0){
        bool found = false;
        search(this, word, pos, found);
        return found;
    }
};

class WordDictionary {
private:
    TrieNode* trie;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        this->trie = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        trie->insert(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return trie->contains(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */