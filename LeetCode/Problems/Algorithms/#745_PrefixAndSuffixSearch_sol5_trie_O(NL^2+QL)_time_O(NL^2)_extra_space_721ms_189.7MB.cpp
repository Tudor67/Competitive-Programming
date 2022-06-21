class Trie{
private:
    static const int ALPHABET_SIZE = 27;
    static const int FIRST_CHAR = 'a';
    static const int SPECIAL_CHAR = FIRST_CHAR + ALPHABET_SIZE - 1;
    int idx;
    Trie* children[ALPHABET_SIZE];
    
public:
    Trie(){
        idx = -1;
        fill(children, children + ALPHABET_SIZE, (Trie*)NULL);
    }
    
    ~Trie(){
        for(int i = 0; i < ALPHABET_SIZE; ++i){
            delete children[i];
        }
    }
    
    void insert(const string& WORD, const int& IDX){
        Trie* node = this;
        for(char c: WORD){
            int edgeID = c - FIRST_CHAR;
            if(node->children[edgeID] == NULL){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
            node->idx = max(node->idx, IDX);
        }
    }
    
    void insertAllPrefixReversedWordEncodings(const string& WORD, const int& IDX){
        const int L = WORD.length();
        const string REVERSED_WORD(WORD.rbegin(), WORD.rend());
        for(int prefixLength = 0; prefixLength <= L; ++prefixLength){
            string prefix(WORD.begin(), WORD.begin() + prefixLength);
            string encoding = prefix + string(1, SPECIAL_CHAR) + REVERSED_WORD;
            insert(encoding, IDX);
        }
    }
    
    int search(const string& PREFIX, const string& SUFFIX){
        const string ENCODING = PREFIX + string(1, SPECIAL_CHAR) + string(SUFFIX.rbegin(), SUFFIX.rend());
        Trie* node = this;
        for(char c: ENCODING){
            int edgeID = c - FIRST_CHAR;
            if(node->children[edgeID] == NULL){
                return -1;
            }
            node = node->children[edgeID];
        }
        return node->idx;
    }
};

class WordFilter {
private:
    Trie trie;
    
public:
    WordFilter(vector<string>& words) {
        const int N = words.size();
        for(int i = 0; i < N; ++i){
            trie.insertAllPrefixReversedWordEncodings(words[i], i);
        }
    }
    
    int f(string prefix, string suffix) {
        return trie.search(prefix, suffix);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */