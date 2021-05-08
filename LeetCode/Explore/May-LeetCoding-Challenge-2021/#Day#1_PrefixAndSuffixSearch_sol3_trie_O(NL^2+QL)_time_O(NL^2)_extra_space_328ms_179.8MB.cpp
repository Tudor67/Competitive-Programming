class Trie{
private:
    int wordIdx;
    vector<Trie*> children;
    
public:
    static const int ALPHABET_SIZE = 27;
    static const int FIRST_ELEM = 'a';
    static const int SPECIAL_ELEM = FIRST_ELEM + ALPHABET_SIZE - 1;
    
public:
    Trie(){
        wordIdx = -1;
        children.resize(ALPHABET_SIZE, NULL);
    }
    
    void add(const string& WORD, const int& WORD_IDX){
        Trie* node = this;
        bool visitedSpecialElem = false;
        int maxWordIdx = WORD_IDX;
        for(char c: WORD){
            int edgeID = c - FIRST_ELEM;
            if(node->children[edgeID] == NULL){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
            if(visitedSpecialElem){
                maxWordIdx = max(node->wordIdx, maxWordIdx);
                node->wordIdx = maxWordIdx;
            }
            if(c == SPECIAL_ELEM){
                visitedSpecialElem = true;
            }
        }
    }
    
    int find(const string& WORD){
        Trie* node = this;
        for(char c: WORD){
            int edgeID = c - FIRST_ELEM;
            if(node->children[edgeID]){
                node = node->children[edgeID];
            }else{
                return -1;
            }
        }
        return node->wordIdx;
    }
};

class WordFilter {
private:
    Trie trie;
    
    string getPrefSufEncoding(const string& PREFIX, const string& SUFFIX){
        return SUFFIX + string(1, Trie::SPECIAL_ELEM) + PREFIX;
    }
    
public:
    WordFilter(vector<string>& words) {
        for(int wordIdx = 0; wordIdx < (int)words.size(); ++wordIdx){
            const string WORD = words[wordIdx];
            const int WORD_LENGTH = WORD.length();
            for(int i = 0; i < WORD_LENGTH; ++i){
                string prefix = WORD;
                string suffix = WORD.substr(i);
                string encoding = getPrefSufEncoding(prefix, suffix);
                trie.add(encoding, wordIdx);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string encoding = getPrefSufEncoding(prefix, suffix);
        return trie.find(encoding);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */