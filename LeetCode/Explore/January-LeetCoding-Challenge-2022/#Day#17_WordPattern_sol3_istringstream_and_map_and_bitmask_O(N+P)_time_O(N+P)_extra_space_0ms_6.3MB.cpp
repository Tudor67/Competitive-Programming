class Solution {
public:
    bool wordPattern(string pattern, string s) {
        const int P = pattern.size();
        const int N = s.length();
        
        unordered_map<string, char> wordToChar;
        int visCharMask = 0;
        
        istringstream ss(s);
        string word;
        int pIdx = 0;
        while(ss >> word){
            if((pIdx == P) ||
               (wordToChar.count(word) && wordToChar[word] != pattern[pIdx]) ||
               (!wordToChar.count(word) && ((visCharMask >> (pattern[pIdx] - 'a')) & 1))){
                return false;
            }
            wordToChar[word] = pattern[pIdx];
            visCharMask |= (1 << (pattern[pIdx] - 'a'));
            pIdx += 1;
        }
        
        return (pIdx == P);
    }
};