class Trie{
private:
    static const int ALPHABET_SIZE = 26;
    static const int FIRST_CHAR = 'a';
    static const int BAD_WORD_IDX = -1;
    int wordIdx;
    Trie* children[ALPHABET_SIZE];
    
public:
    Trie(){
        wordIdx = BAD_WORD_IDX;
        fill(children, children + ALPHABET_SIZE, nullptr);
    }
    
    ~Trie(){
        for(int edgeID = 0; edgeID < ALPHABET_SIZE; ++edgeID){
            delete children[edgeID];
        }
    }
    
    void insert(const string& WORD, const int& WORD_IDX){
        Trie* node = this;
        for(char c: WORD){
            int edgeID = c - FIRST_CHAR;
            if(node->children[edgeID] == nullptr){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
        }
        node->wordIdx = WORD_IDX;
    }
    
    int getWordIdx(const string& WORD, const int& FIRST_POS, const int& LAST_POS, const int& DIR){
        Trie* node = this;
        for(int pos = FIRST_POS; pos != LAST_POS + DIR; pos += DIR){
            int edgeID = WORD[pos] - FIRST_CHAR;
            if(node->children[edgeID] == nullptr){
                return BAD_WORD_IDX;
            }
            node = node->children[edgeID];
        }
        return node->wordIdx;
    }
};

class Solution {
private:
    bool isPalindrome(const string& WORD, const int& FIRST_POS, const int& LAST_POS){
        for(int i = FIRST_POS, j = LAST_POS; i < j; ++i, --j){
            if(WORD[i] != WORD[j]){
                return false;
            }
        }
        return true;
    }
    
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        const int N = words.size();
        
        Trie trie;
        for(int i = 0; i < N; ++i){
            trie.insert(words[i], i);
        }
        
        vector<vector<int>> res;
        for(int i = 0; i < N; ++i){
            const int L = words[i].length();
            for(int len = 0; len <= L; ++len){
                if(isPalindrome(words[i], L - len, L - 1)){
                    int j = trie.getWordIdx(words[i], L - len - 1, 0, -1);
                    if(0 <= j && j < N && i != j){
                        res.push_back({i, j});
                    }
                }
                if(isPalindrome(words[i], 0, len - 1)){
                    int j = trie.getWordIdx(words[i], L - 1, len, -1);
                    if(0 <= j && j < N && i != j && len != 0){
                        res.push_back({j, i});
                    }
                }
            }
        }
        
        return res;
    }
};