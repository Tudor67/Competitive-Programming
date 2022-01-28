class Trie{
private:
    static const int ALPHABET_SIZE = 27;
    static const int FIRST_ELEM = 'a';
    bool isTerminalNode;
    Trie* children[ALPHABET_SIZE];
    
    bool contains(const string& WORD, int idx, Trie* node){
        if(node == NULL){
            return false;
        }
        if(idx == (int)WORD.length()){
            return node->isTerminalNode;
        }
        int startEdgeID = WORD[idx] - FIRST_ELEM;
        int endEdgeID = startEdgeID;
        if(WORD[idx] == '.'){
            startEdgeID = 0;
            endEdgeID = ALPHABET_SIZE - 1;
        }
        for(int edgeID = startEdgeID; edgeID <= endEdgeID; ++edgeID){
            if(contains(WORD, idx + 1, node->children[edgeID])){
                return true;
            }
        }
        return false;
    }
    
public:
    Trie(){
        isTerminalNode = false;
        fill(children, children + ALPHABET_SIZE, (Trie*)NULL);
    }
    
    ~Trie(){
        for(int edgeID = 0; edgeID < ALPHABET_SIZE; ++edgeID){
            delete children[edgeID];
        }
    }
    
    void insert(const string& WORD){
        Trie* node = this;
        for(char c: WORD){
            int edgeID = c - FIRST_ELEM;
            if(node->children[edgeID] == NULL){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
        }
        node->isTerminalNode = true;
    }
    
    bool contains(const string& WORD){
        return contains(WORD, 0, this);
    }
};

class WordDictionary {
private:
    Trie trie;
    
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        trie.insert(word);
    }
    
    bool search(string word) {
        return trie.contains(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */