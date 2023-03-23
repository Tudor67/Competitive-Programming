class Trie{
private:
    static const int ALPHABET_SIZE = 26;
    static const int FIRST_CHAR = 'a';
    static const int SPECIAL_CHAR = '.';
    bool isTerminalNode;
    Trie* children[ALPHABET_SIZE];

    bool search(const string& WORD, int index, Trie* node){
        if(index == (int)WORD.length()){
            return node->isTerminalNode;
        }
        bool found = false;
        int firstEdgeID = (WORD[index] == SPECIAL_CHAR ? 0 : WORD[index] - FIRST_CHAR);
        int lastEdgeID = (WORD[index] == SPECIAL_CHAR ? ALPHABET_SIZE - 1 : WORD[index] - FIRST_CHAR);
        for(int edgeID = firstEdgeID; !found && edgeID <= lastEdgeID; ++edgeID){
            if(node->children[edgeID] != nullptr){
                found = found || search(WORD, index + 1, node->children[edgeID]);
            }
        }
        return found;
    }

public:
    Trie(){
        isTerminalNode = false;
        fill(children, children + ALPHABET_SIZE, nullptr);
    }

    ~Trie(){
        for(int edgeID = 0; edgeID < ALPHABET_SIZE; ++edgeID){
            delete children[edgeID];
        }
    }

    void insert(const string& WORD){
        Trie* node = this;
        for(char c: WORD){
            int edgeID = c - FIRST_CHAR;
            if(node->children[edgeID] == nullptr){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
        }
        node->isTerminalNode = true;
    }

    bool search(const string& WORD){
        return search(WORD, 0, this);
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
        return trie.search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */