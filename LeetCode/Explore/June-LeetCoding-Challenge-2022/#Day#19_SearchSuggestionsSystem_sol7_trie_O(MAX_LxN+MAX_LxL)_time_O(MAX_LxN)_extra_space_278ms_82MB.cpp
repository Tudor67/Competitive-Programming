class Trie{
private:
    static const int ALPHABET_SIZE = 26;
    static const int FIRST_CHAR = 'a';
    bool isTerminalNode;
    Trie* children[ALPHABET_SIZE];
    
    void collectWordsWithGivenPrefix(int level, Trie* node, string& currentWord, const string& PREFIX,
                                     vector<string>& res, const int& MAX_WORDS){
        if(currentWord.length() >= PREFIX.length()){
            if(node->isTerminalNode){
                res.push_back(currentWord);
            }
        }
        int startEdgeID = (currentWord.length() < PREFIX.length() ? PREFIX[level] - FIRST_CHAR : 0);
        int endEdgeID = (currentWord.length() < PREFIX.length() ? PREFIX[level] - FIRST_CHAR : ALPHABET_SIZE - 1);
        for(int edgeID = startEdgeID; edgeID <= endEdgeID && (int)res.size() < MAX_WORDS; ++edgeID){
            if(node->children[edgeID] != NULL){
                currentWord.push_back(char(FIRST_CHAR + edgeID));
                collectWordsWithGivenPrefix(level + 1, node->children[edgeID], currentWord, PREFIX, res, MAX_WORDS);
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
    
    void collectWordsWithGivenPrefix(const string& PREFIX, vector<string>& res, const int& MAX_WORDS){
        string currentWord;
        collectWordsWithGivenPrefix(0, this, currentWord, PREFIX, res, MAX_WORDS);
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
        for(int j = 0; j < L; ++j){
            string prefix = searchWord.substr(0, j + 1);
            trie.collectWordsWithGivenPrefix(prefix, res[j], 3);
        }
        
        return res;
    }
};