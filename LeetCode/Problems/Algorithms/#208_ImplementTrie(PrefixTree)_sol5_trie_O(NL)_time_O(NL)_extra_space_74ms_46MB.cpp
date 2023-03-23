class Trie {
private:
    static const int ALPHABET_SIZE = 26;
    static const int FIRST_CHAR = 'a';
    bool isTerminalNode;
    Trie* children[ALPHABET_SIZE];

    Trie* find(const string& WORD){
        Trie* node = this;
        for(int i = 0; i < (int)WORD.length() && node != nullptr; ++i){
            int edgeID = WORD[i] - FIRST_CHAR;
            node = node->children[edgeID];
        }
        return node;
    }

public:
    Trie() {
        isTerminalNode = false;
        fill(children, children + ALPHABET_SIZE, nullptr);
    }

    ~Trie(){
        for(int edgeID = 0; edgeID < ALPHABET_SIZE; ++edgeID){
            delete children[edgeID];
        }
    }
    
    void insert(string word) {
        Trie* node = this;
        for(char c: word){
            int edgeID = c - FIRST_CHAR;
            if(node->children[edgeID] == nullptr){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
        }
        node->isTerminalNode = true;
    }
    
    bool search(string word) {
        Trie* node = find(word);
        return (node != nullptr && node->isTerminalNode);
    }
    
    bool startsWith(string prefix) {
        Trie* node = find(prefix);
        return (node != nullptr);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */