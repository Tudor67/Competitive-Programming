class TrieNode{
public:
    static const int ALPHABET_SIZE = 27;
    static const char FIRST_LETTER = char('a' - 1);
    int max_weight;
    vector<TrieNode*> children;
    
    TrieNode(){
        this->max_weight = 0;
        this->children.resize(ALPHABET_SIZE, NULL);
    }
    
    void insert(const string& word, const int& weight){
        TrieNode* node = this;
        for(char c: word){
            short int edge_id = c - FIRST_LETTER;
            if(node->children[edge_id] == NULL){
                node->children[edge_id] = new TrieNode();
            }
            node = node->children[edge_id];
            node->max_weight = max(weight, node->max_weight);
        }
    }
    
    void insert_prefixes_and_suffixes(const string& word, const int& weight){
        for(int pos = (int)word.length(); pos >= 0; --pos){
            insert(word.substr(pos) + string(1, FIRST_LETTER) + word, weight);
        }
    }
    
    int get_max_weight(const string& prefix, const string& suffix){
        string word = suffix + string(1, FIRST_LETTER) + prefix;
        TrieNode* node = this;
        for(char c: word){
            short int edge_id = c - FIRST_LETTER;
            if(node->children[edge_id] == NULL){
                return -1;
            }
            node = node->children[edge_id];
        }
        return node->max_weight;
    }
};

class WordFilter {
private:
    TrieNode* trie;
    
public:
    WordFilter(vector<string>& words) {
        this->trie = new TrieNode();
        for(int i = 0; i < words.size(); ++i){
            trie->insert_prefixes_and_suffixes(words[i], i);
        }
    }
    
    int f(string prefix, string suffix) {
        return trie->get_max_weight(prefix, suffix);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */