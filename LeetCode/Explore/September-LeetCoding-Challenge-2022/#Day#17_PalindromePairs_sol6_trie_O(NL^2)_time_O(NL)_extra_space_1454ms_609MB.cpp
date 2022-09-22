class Palindrome{
public:
    static bool isPalindrome(const string& WORD, const int& FIRST_POS, const int& LAST_POS){
        for(int i = FIRST_POS, j = LAST_POS; i < j; ++i, --j){
            if(WORD[i] != WORD[j]){
                return false;
            }
        }
        return true;
    }
};

class Trie{
public:
    static const int ALPHABET_SIZE = 26;
    static const int FIRST_CHAR = 'a';
    static const int BAD_WORD_IDX = -1;
    int wordIdx;
    Trie* children[ALPHABET_SIZE];
    vector<int> indicesOfPalindromeSuffixes;
    
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
        const int L = WORD.length();
        Trie* node = this;
        for(int pos = 0; pos < L; ++pos){
            if(Palindrome::isPalindrome(WORD, pos, L - 1)){
                node->indicesOfPalindromeSuffixes.push_back(WORD_IDX);
            }
            int edgeID = WORD[pos] - FIRST_CHAR;
            if(node->children[edgeID] == nullptr){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
        }
        node->wordIdx = WORD_IDX;
        node->indicesOfPalindromeSuffixes.push_back(WORD_IDX);
    }
    
    Trie* getNextNode(char c){
        int edgeID = c - FIRST_CHAR;
        return children[edgeID];
    }
};

class Solution {
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
            Trie* node = &trie;
            for(int pos = L - 1; pos >= 0 && node != nullptr; --pos){
                if(node->wordIdx != node->BAD_WORD_IDX && node->wordIdx != i){
                    if(Palindrome::isPalindrome(words[i], 0, pos)){
                        res.push_back({node->wordIdx, i});
                    }
                }
                node = node->getNextNode(words[i][pos]);
            }
            if(node != nullptr){
                for(int idx: node->indicesOfPalindromeSuffixes){
                    if(idx != i){
                        res.push_back({idx, i});
                    }
                }
            }
        }
        
        return res;
    }
};