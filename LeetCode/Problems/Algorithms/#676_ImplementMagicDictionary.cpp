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
    
    void insert(const string& word){
        TrieNode* node = this;
        for(char c: word){
            short int edge_id = c - FIRST_LETTER;
            if(node->children[edge_id] == NULL){
                node->children[edge_id] = new TrieNode();
            }
            node = node->children[edge_id];
        }
        node->is_terminal_node = true;
    }
    
    bool search(TrieNode* node, const string& word, int pos, int ignored_pos){
        if(node != NULL && pos < word.length()){
            char start_char = word[pos];
            char end_char = word[pos];
            char ignored_char = '?';
            if(pos == ignored_pos){
                start_char = FIRST_LETTER;
                end_char = FIRST_LETTER + ALPHABET_SIZE - 1;
                ignored_char = word[ignored_pos];
            }
            
            bool found = false;
            for(char c = start_char; c <= end_char; ++c){
                short int edge_id = c - FIRST_LETTER;
                if(c != ignored_char && node->children[edge_id]){
                    found = found || search(node->children[edge_id], word, pos + 1, ignored_pos);
                }
            }
            return found;
        }
        
        return (node != NULL && node->is_terminal_node); 
    }
    
    bool special_search(const string& word){
        bool found = false;
        for(int ignored_pos = 0; !found && ignored_pos < word.length(); ++ignored_pos){
            found = found || search(this, word, 0, ignored_pos);
        }
        return found;
    }
    
};

class MagicDictionary {
private:
    TrieNode* trie;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        this->trie = new TrieNode();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(const string& word: dict){
            trie->insert(word);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        return trie->special_search(word);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */