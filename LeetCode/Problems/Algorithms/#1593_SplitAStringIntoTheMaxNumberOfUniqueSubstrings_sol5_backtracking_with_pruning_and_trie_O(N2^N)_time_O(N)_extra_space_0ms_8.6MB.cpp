class Trie{
private:
    static const int ALPHABET_SIZE = 26;
    static const char FIRST_CHAR = 'a';
    bool isTerminalNode;
    vector<Trie*> children;
    
public:
    Trie(){
        isTerminalNode = false;
        children.resize(ALPHABET_SIZE, NULL);
    }
    
    void insert(const string& WORD, const int& START_POS, const int& END_POS){
        Trie* node = this;
        for(int i = START_POS; i <= END_POS; ++i){
            short int edgeID = WORD[i] - FIRST_CHAR;
            if(node->children[edgeID] == NULL){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
        }
        node->isTerminalNode = true;
    }
    
    void erase(const string& WORD, const int& START_POS, const int& END_POS){
        Trie* node = this;
        for(int i = START_POS; i <= END_POS; ++i){
            short int edgeID = WORD[i] - FIRST_CHAR;
            if(node->children[edgeID] == NULL){
                return;
            }
            node = node->children[edgeID];
        }
        node->isTerminalNode = false;
    }
    
    bool contains(const string& WORD, const int& START_POS, const int& END_POS){
        Trie* node = this;
        for(int i = START_POS; i <= END_POS; ++i){
            short int edgeID = WORD[i] - FIRST_CHAR;
            if(node->children[edgeID] == NULL){
                return false;
            }
            node = node->children[edgeID];
        }
        return node->isTerminalNode;
    }
};

class Solution {
private:
    void back(int prevPos, const string& S, Trie& substrings, int substringsCount, int& answer){
        if(prevPos == S.length()){
            answer = max(substringsCount, answer);
        }else if((int)S.length() - prevPos + substringsCount > answer){
            for(int pos = prevPos; pos < S.length(); ++pos){
                if(!substrings.contains(S, prevPos, pos)){
                    substrings.insert(S, prevPos, pos);
                    back(pos + 1, S, substrings, substringsCount + 1,answer);
                    substrings.erase(S, prevPos, pos);
                }
            }
        }
    }
    
public:
    int maxUniqueSplit(string s) {
        Trie substrings;
        int answer = 1;
        back(0, s, substrings, 0, answer);
        return answer;
    }
};