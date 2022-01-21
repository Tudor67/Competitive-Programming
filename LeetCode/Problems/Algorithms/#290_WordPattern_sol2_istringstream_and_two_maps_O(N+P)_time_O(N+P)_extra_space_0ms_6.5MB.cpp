class Solution {
public:
    bool wordPattern(string pattern, string s) {
        const int P = pattern.size();
        const int N = s.length();
        
        unordered_map<string, char> wordToChar;
        unordered_map<char, string> charToWord;
        
        istringstream ss(s);
        string word;
        int pIdx = 0;
        while(ss >> word){
            if((pIdx == P) ||
               (wordToChar.count(word) && wordToChar[word] != pattern[pIdx]) ||
               (charToWord.count(pattern[pIdx]) && charToWord[pattern[pIdx]] != word)){
                return false;
            }
            wordToChar[word] = pattern[pIdx];
            charToWord[pattern[pIdx]] = word;
            pIdx += 1;
        }
        
        return (pIdx == P);
    }
};