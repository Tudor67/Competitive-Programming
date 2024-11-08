class Trie{
private:
    static const int ALPHABET_SIZE = 26;
    static const int FIRST_ELEM = 'a';
    int wordIdx;
    int wordLen;
    Trie* children[ALPHABET_SIZE];
    
public:
    Trie(){
        wordIdx = -1;
        wordLen = INT_MAX;
        fill(begin(children), end(children), nullptr);
    }
    
    ~Trie(){
        for(int edgeID = 0; edgeID < ALPHABET_SIZE; ++edgeID){
            delete children[edgeID];
        }
    }
    
    void reverseInsert(const string& WORD, const int WORD_IDX){
        const int WORD_LEN = WORD.length();
        
        Trie* node = this;
        
        if(node->wordLen > WORD_LEN){
            node->wordIdx = WORD_IDX;
            node->wordLen = WORD_LEN;
        }
        
        for(int i = WORD_LEN - 1; i >= 0; --i){
            int edgeID = WORD[i] - FIRST_ELEM;
            if(node->children[edgeID] == nullptr){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
            if(node->wordLen > WORD_LEN){
                node->wordIdx = WORD_IDX;
                node->wordLen = WORD_LEN;
            }
        }
    }
    
    int query(const string& WORD){
        const int WORD_LEN = WORD.length();
        Trie* node = this;
        for(int i = WORD_LEN - 1; i >= 0; --i){
            int edgeID = WORD[i] - FIRST_ELEM;
            if(node->children[edgeID] == nullptr){
                break;
            }
            node = node->children[edgeID];
        }
        return node->wordIdx;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        const int W = wordsContainer.size();
        const int Q = wordsQuery.size();

        Trie trie;
        for(int i = 0; i < W; ++i){
            trie.reverseInsert(wordsContainer[i], i);
        }
        
        vector<int> res(Q);
        for(int i = 0; i < Q; ++i){
            res[i] = trie.query(wordsQuery[i]);
        }
        
        return res;
    }
};