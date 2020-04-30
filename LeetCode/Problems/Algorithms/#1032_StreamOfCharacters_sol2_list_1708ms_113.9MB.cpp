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
};

class StreamChecker {
private:
    TrieNode* root;        // root of the trie
    list<TrieNode*> nodes; // current nodes
    
public:
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        for(const string& word: words){
            root->insert(word);
        }
    }
    
    bool query(char letter) {
        short int edge_id = letter - TrieNode::FIRST_LETTER;
        bool found = false;
        nodes.push_back(root);
        list<TrieNode*>::iterator it = nodes.begin();
        while(it != nodes.end()){
            TrieNode* node = *it;
            if(node->children[edge_id] != NULL){
                found |= node->children[edge_id]->is_terminal_node;
                *it = node->children[edge_id];
                ++it;
            }else{
                it = nodes.erase(it);
            }
        }
        return found;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */