class Trie{
private:
    static const int ALPHABET_SIZE = 26;
    static const int FIRST_ELEM = 'a';
    bool isTerminalNode;
    Trie* children[ALPHABET_SIZE];
    
public:
    Trie(){
        isTerminalNode = false;
        fill(children, children + ALPHABET_SIZE, nullptr);
    }
    
    bool insert(const string& WORD, const int& START_IDX, const int& LEN){
        Trie* node = this;
        for(int i = START_IDX; i < START_IDX + LEN; ++i){
            int edgeID = WORD[i] - FIRST_ELEM;
            if(node->children[edgeID] == nullptr){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
        }
        bool newInsertion = !node->isTerminalNode;
        node->isTerminalNode = true;
        return newInsertion;
    }
};

class Solution {
public:
    int distinctEchoSubstrings(string text) {
        const int N = text.length();
        int answer = 0;
        
        Trie trie;
        for(int len = 1; 2 * len <= N; ++len){
            int matchCount = 0;
            for(int i = 0; i < len; ++i){
                matchCount += (text[i] == text[i + len]);
            }
            if(matchCount == len){
                answer += trie.insert(text, 0, len);
            }
            
            for(int i = 1; i + 2 * len - 1 < N; ++i){
                matchCount -= (text[i - 1] == text[i + len - 1]);
                matchCount += (text[i + len - 1] == text[i + 2 * len - 1]);
                if(matchCount == len){
                    answer += trie.insert(text, i, len);
                }
            }
        }
        
        return answer;
    }
};