class Trie{
private:
    static const int ALPHABET_SIZE = 26;
    static const char FIRST_LETTER = 'a';
    static const char LAST_LETTER = FIRST_LETTER + ALPHABET_SIZE - 1;
    int terminalNodeCnt;
    vector<Trie*> children;
    
public:
    Trie(){
        terminalNodeCnt = 0;
        children.resize(ALPHABET_SIZE, NULL);
    }
    
    void insert(const string& WORD){
        Trie* node = this;
        for(char c: WORD){
            short int edgeID = c - FIRST_LETTER;
            if(node->children[edgeID] == NULL){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
        }
        node->terminalNodeCnt += 1;
    }
    
    int count(const string& WORD){
        Trie* node = this;
        for(char c: WORD){
            short int edgeID = c - FIRST_LETTER;
            if(node->children[edgeID] == NULL){
                return 0;
            }
            node = node->children[edgeID];
        }
        return node->terminalNodeCnt;
    }
};

class Solution {
public:
    int countSubstrings(string s, string t) {
        Trie tDict;
        for(int pos = 0; pos < t.length(); ++pos){
            for(int len = 1; pos + len - 1 < t.length(); ++len){
                tDict.insert(t.substr(pos, len));
            }
        }
        
        int answer = 0;
        for(int pos = 0; pos < s.length(); ++pos){
            for(int len = 1; pos + len - 1 < s.length(); ++len){
                string sSubstr = s.substr(pos, len);
                for(int i = 0; i < sSubstr.length(); ++i){
                    char originalChar = sSubstr[i];
                    for(int newChar = 'a'; newChar <= 'z'; ++newChar){
                        if(newChar != originalChar){
                            sSubstr[i] = newChar;
                            answer += tDict.count(sSubstr);
                        }
                    }
                    sSubstr[i] = originalChar;
                }
            }
        }
        
        return answer;
    }
};