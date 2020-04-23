class TrieNode{
public:
    static const int ALPHABET_SIZE = 26;
    static const char FIRST_LETTER = 'a';
    bool is_terminal_node;
    vector<TrieNode*> children;
    int val;
    int sum;
    
    TrieNode(){
        this->is_terminal_node = false;
        this->children.resize(ALPHABET_SIZE, NULL);
        this->val = 0;
        this->sum = 0;
    }
    
    void insert(TrieNode* node, const string& key, int pos, int& val){
        if(pos == key.length()){
            node->is_terminal_node = true;
            int prev_val = node->val;
            node->val = val;
            val -= prev_val;
        }else{
            short int edge_id = key[pos] - FIRST_LETTER;
            if(node->children[edge_id] == NULL){
                node->children[edge_id] = new TrieNode();
            }
            insert(node->children[edge_id], key, pos + 1, val);
        }
        node->sum += val;
    }
    
    void insert(const string& key, int val){
        insert(this, key, 0, val);
    }
    
    int get_sum(const string& prefix){
        TrieNode* node = this;
        for(char c: prefix){
            short int edge_id = c - FIRST_LETTER;
            if(node->children[edge_id] == NULL){
                return 0;
            }
            node = node->children[edge_id];
        }
        return node->sum;
    }
};

class MapSum {
private:
    TrieNode* trie;
public:
    /** Initialize your data structure here. */
    MapSum() {
        this->trie = new TrieNode();
    }
    
    void insert(string key, int val) {
        trie->insert(key, val);
    }
    
    int sum(string prefix) {
        return trie->get_sum(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */