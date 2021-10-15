class Trie {
private:
    static const int ALPHABET_SIZE = 26;
    static const char FIRST_ELEM = 'a';
    bool isTerminalNode;
    Trie* children[ALPHABET_SIZE];
    
    Trie* find(const string& PREFIX){
        Trie* node = this;
        for(char c: PREFIX){
            int edgeID = c - FIRST_ELEM;
            if(node->children[edgeID] == NULL){
                return NULL;
            }
            node = node->children[edgeID];
        }
        return node;
    }
    
public:
    Trie() {
        isTerminalNode = false;
        fill(children, children + ALPHABET_SIZE, (Trie*)NULL);
    }
    
    ~Trie(){
        for(int edgeID = 0; edgeID < ALPHABET_SIZE; ++edgeID){
            if(children[edgeID] != NULL){
                // https://isocpp.org/wiki/faq/freestore-mgmt#two-steps-of-delete
                // `delete ptr` does two things:
                // 1) it calls the destructor;
                // 2) it deallocates the memory;
                // So, the memory of the current node is released only when all descendants of the current node are destroyed
                delete children[edgeID];
            }
        }
        // Calling order of destructors and memory deallocations:
        // level 1: ~Trie()
        // level 2:   ~Trie()
        // level 3:     ~Trie()
        // level 3:     deallocate memory
        // level 2:   deallocate memory
        // level 1: deallocate memory
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
        Trie* node = find(word);
        return (node != NULL && node->isTerminalNode);
    }
    
    bool startsWith(string prefix) {
        Trie* node = find(prefix);
        return (node != NULL);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */