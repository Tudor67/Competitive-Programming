class Trie{
private:
    static const int ALPHABET_SIZE = 26;
    static const char FIRST_ELEM = 'a';
    int terminalNodeCount;
    Trie* children[ALPHABET_SIZE];
    
public:
    Trie(){
        terminalNodeCount = 0;
        fill(children, children + ALPHABET_SIZE, (Trie*)NULL);
    }
    
    ~Trie(){
        for(int edgeID = 0; edgeID < ALPHABET_SIZE; ++edgeID){
            delete children[edgeID];
        }
    }
    
    void add(const string& WORD, const int& START_POS){
        Trie* node = this;
        for(int pos = START_POS; pos < (int)WORD.length(); ++pos){
            int edgeID = WORD[pos] - FIRST_ELEM;
            if(node->children[edgeID] == NULL){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
            node->terminalNodeCount += 1;
        }
    }
    
    int count(const string& WORD){
        Trie* node = this;
        for(char c: WORD){
            int edgeID = c - FIRST_ELEM;
            if(node->children[edgeID] == NULL){
                return 0;
            }
            node = node->children[edgeID];
        }
        return node->terminalNodeCount;
    }
};

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        Trie trie;
        for(const string& WORD: words){
            const int L = WORD.length();
            for(int i = 0; i < L; ++i){
                trie.add(WORD, i);
            }
        }
        
        vector<string> answer;
        for(const string& WORD: words){
            if(trie.count(WORD) >= 2){
                answer.push_back(WORD);
            }
        }
        
        return answer;
    }
};