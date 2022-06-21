class Trie{
private:
    static const int ALPHABET_SIZE = 26;
    static const int FIRST_CHAR = 'a';
    bool isTerminalNode;
    Trie* children[ALPHABET_SIZE];
    
    void collectSuggestions(Trie* node, string& currentWord, const string& SEARCH_WORD, int longestCommonPrefixLength,
                            vector<vector<string>>& res, const int& MAX_SUGGESTIONS_PER_PREFIX){
        if(node->isTerminalNode){
            for(int i = longestCommonPrefixLength - 1; i >= 0 && (int)res[i].size() < MAX_SUGGESTIONS_PER_PREFIX; --i){
                res[i].push_back(currentWord);
            }
        }
        for(int edgeID = 0; edgeID < ALPHABET_SIZE; ++edgeID){
            if(node->children[edgeID] != NULL){
                currentWord.push_back(char(FIRST_CHAR + edgeID));
                int len = currentWord.length();
                int match = (longestCommonPrefixLength == len - 1 && currentWord[len - 1] == SEARCH_WORD[len - 1]);
                collectSuggestions(node->children[edgeID], currentWord, SEARCH_WORD, longestCommonPrefixLength + match,
                                   res, MAX_SUGGESTIONS_PER_PREFIX);
                currentWord.pop_back();
            }
        }
    }
    
public:
    Trie(){
        isTerminalNode = false;
        fill(children, children + ALPHABET_SIZE, (Trie*)NULL);
    }
    
    ~Trie(){
        for(int i = 0; i < ALPHABET_SIZE; ++i){
            delete children[i];
        }
    }
    
    void insert(const string& WORD){
        Trie* node = this;
        for(char c: WORD){
            int edgeID = c - FIRST_CHAR;
            if(node->children[edgeID] == NULL){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
        }
        node->isTerminalNode = true;
    }
    
    void collectSuggestions(const string& SEARCH_WORD, vector<vector<string>>& res, const int& MAX_SUGGESTIONS_PER_PREFIX){
        string currentWord;
        int longestCommonPrefixLength = 0;
        collectSuggestions(this, currentWord, SEARCH_WORD, longestCommonPrefixLength, res, MAX_SUGGESTIONS_PER_PREFIX);
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        const int N = products.size();
        const int L = searchWord.length();
        
        Trie trie;
        for(const string& PRODUCT: products){
            trie.insert(PRODUCT);
        }
        
        vector<vector<string>> res(L);
        trie.collectSuggestions(searchWord, res, 3);
        
        return res;
    }
};