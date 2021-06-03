class Trie{
public:
    static const int ALPHABET_SIZE = 26;
    static const int FIRST_LETTER = 'a';
    int terminalNodeCnt;
    vector<Trie*> children;
    
public:
    Trie(){
        terminalNodeCnt = 0;
        children.resize(ALPHABET_SIZE, NULL);
    }
    
    int insert(const string& WORD, const int& START_POS, const int& SIZE){
        Trie* node = this;
        for(int i = START_POS; i < START_POS + SIZE; ++i){
            short int edgeID = WORD[i] - FIRST_LETTER;
            if(node->children[edgeID] == NULL){
                node->children[edgeID] = new Trie();
            }
            node = node->children[edgeID];
        }
        node->terminalNodeCnt += 1;
        return node->terminalNodeCnt;
    }
};

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        const int N = s.length();
        const int MAX_LETTER = 'z';
        
        int answer = 0;
        Trie validSubstrings;
        vector<int> letterCnt(MAX_LETTER + 1, 0);
        for(int i = 0; i + minSize - 1 < N; ++i){
            fill(letterCnt.begin(), letterCnt.end(), 0);
            int uniqueLetters = 0;
            for(int size = 1; size <= minSize; ++size){
                uniqueLetters += (letterCnt[s[i + size - 1]] == 0);
                letterCnt[s[i + size - 1]] += 1;
            }
            if(uniqueLetters <= maxLetters){
                int validSubstringsCnt = validSubstrings.insert(s, i, minSize);
                answer = max(validSubstringsCnt, answer);
            }
        }
        
        return answer;
    }
};