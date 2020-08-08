class TrieNode{
public:
    static const int ALPHABET_SIZE = 26;
    static const char FIRST_LETTER = 'a';
    bool is_terminal_node;
    vector<TrieNode*> children;
    
    TrieNode(){
        this->is_terminal_node = false;
        this->children.resize(ALPHABET_SIZE, NULL);
    }

    void insert(TrieNode* root, const string& WORD){
        TrieNode* node = root;
        for(char c: WORD){
            short int edge_id = c - FIRST_LETTER;
            if(node->children[edge_id] == NULL){
                node->children[edge_id] = new TrieNode();
            }
            node = node->children[edge_id];
        }
        node->is_terminal_node = true;
    }
    
    bool contains(TrieNode* node, const string& WORD, int pos){
        if(node == NULL){
            return false;
        }
        if(pos == WORD.length()){
            return node->is_terminal_node;
        }
        if(isalpha(WORD[pos])){
            short int edge_id = WORD[pos] - FIRST_LETTER;
            return contains(node->children[edge_id], WORD, pos + 1);
        }
        bool found = false;
        for(short int edge_id = 0; edge_id < ALPHABET_SIZE; ++edge_id){
            if(!found && node->children[edge_id]){
                found |= contains(node->children[edge_id], WORD, pos + 1);
            }
        }
        return found;
    }
    
    void insert(const string& WORD){
        insert(this, WORD);
    }
    
    bool contains(const string& WORD){
        return contains(this, WORD, 0);
    }
};


class WordDictionary {
public:
    TrieNode* trie;
    
    /** Initialize your data structure here. */
    WordDictionary() {
        trie = new TrieNode();
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