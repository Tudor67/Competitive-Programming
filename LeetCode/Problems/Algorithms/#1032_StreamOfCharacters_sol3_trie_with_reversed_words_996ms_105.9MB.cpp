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
    
    void insert(string::const_reverse_iterator CRIT_BEGIN, string::const_reverse_iterator CRIT_END){
        TrieNode* node = this;
        for(string::const_reverse_iterator crit = CRIT_BEGIN; crit != CRIT_END; ++crit){
            short int edge_id = *crit - FIRST_LETTER;
            if(node->children[edge_id] == NULL){
                node->children[edge_id] = new TrieNode();
            }
            node = node->children[edge_id];
        }
        node->is_terminal_node = true;
    }
    
    bool contains_prefix(string::const_reverse_iterator CRIT_BEGIN, string::const_reverse_iterator CRIT_END){
        TrieNode* node = this;
        for(string::const_reverse_iterator crit = CRIT_BEGIN; crit != CRIT_END; ++crit){
            short int edge_id = *crit - FIRST_LETTER;
            if(node->children[edge_id] == NULL){
                return false;
            }
            if(node->children[edge_id]->is_terminal_node){
                return true;
            }
            node = node->children[edge_id];
        }
        return false;
    }
};

class StreamChecker {
private:
    TrieNode* trie;
    string char_stream;
    
public:
    StreamChecker(vector<string>& words) {
        trie = new TrieNode();
        for(const string& WORD: words){
            trie->insert(WORD.crbegin(), WORD.crend());
        }
    }
    
    bool query(char letter) {
        char_stream += letter;
        return trie->contains_prefix(char_stream.crbegin(), char_stream.crend());
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */