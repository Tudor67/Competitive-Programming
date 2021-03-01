class Trie{
private:
    static const int ALPHABET_SIZE = 26;
    static const char FIRST_LETTER = 'a';
    vector<Trie*> children;
    bool isTerminalNode;
    
    void search(Trie* node, string& currentWord, string& longestWord, const string& S, const int& START_POS){
        if(node != NULL && START_POS < (int)S.length()){
            for(char c = FIRST_LETTER; c < Trie::FIRST_LETTER + Trie::ALPHABET_SIZE; ++c){
                short int edgeID = c - Trie::FIRST_LETTER;
                if(node->children[edgeID] != NULL){
                    int pos = S.find(c, START_POS);
                    if(pos != string::npos){
                        currentWord.push_back(c);
                        if(node->children[edgeID]->isTerminalNode && currentWord.size() > longestWord.size()){
                            longestWord = currentWord;
                        }
                        search(node->children[edgeID], currentWord, longestWord, S, pos + 1);
                        currentWord.pop_back();
                    }
                }
            }
        }
    }
    
public:
    Trie(){
        children.resize(Trie::ALPHABET_SIZE, NULL);
        isTerminalNode = false;
    }
    
    void insert(const string& WORD){
        Trie* node = this;
        for(char c: WORD){
            short int edgeID = c - Trie::FIRST_LETTER;
            if(node->children[edgeID] == NULL){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
        }
        node->isTerminalNode = true;
    }
    
    string findLongestWordFrom(const string& S){
        string currentWord;
        string longestWord;
        search(this, currentWord, longestWord, S, 0);
        return longestWord;
    }
};

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        Trie trie;
        for(const string& WORD: d){
            trie.insert(WORD);
        }
        return trie.findLongestWordFrom(s);
    }
};