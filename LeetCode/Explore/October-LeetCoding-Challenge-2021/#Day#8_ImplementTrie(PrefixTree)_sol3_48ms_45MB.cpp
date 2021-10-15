class Trie {
private:
    static const int ALPHABET_SIZE = 26;
    static const char FIRST_ELEM = 'a';
    bool isTerminalNode;
    Trie* children[ALPHABET_SIZE];
    
public:
    Trie() {
        isTerminalNode = false;
        fill(children, children + ALPHABET_SIZE, (Trie*)NULL);
    }
    
    void insert(string word) {
        Trie* node = this;
        for(char c: word){
            int edgeID = c - FIRST_ELEM;
            if(node->children[edgeID] == NULL){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
        }
        node->isTerminalNode = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for(char c: word){
            int edgeID = c - FIRST_ELEM;
            if(node->children[edgeID] == NULL){
                return false;
            }
            node = node->children[edgeID];
        }
        return node->isTerminalNode;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(char c: prefix){
            int edgeID = c - FIRST_ELEM;
            if(node->children[edgeID] == NULL){
                return false;
            }
            node = node->children[edgeID];
        }
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