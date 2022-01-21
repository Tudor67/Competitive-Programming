class Solution {
public:
    bool wordPattern(string pattern, string s) {
        const int P = pattern.size();
        const int N = s.length();
        
        unordered_map<string, char> wordToChar;
        unordered_map<char, string> charToWord;
        
        string word;
        int pIdx = 0;
        for(int i = 0; i < N; ++i){
            if(s[i] != ' '){
                word += s[i];
            }
            if(i + 1 == N || s[i + 1] == ' '){
                if((pIdx == P) ||
                   (wordToChar.count(word) && wordToChar[word] != pattern[pIdx]) ||
                   (charToWord.count(pattern[pIdx]) && charToWord[pattern[pIdx]] != word)){
                    return false;
                }
                wordToChar[word] = pattern[pIdx];
                charToWord[pattern[pIdx]] = word;
                pIdx += 1;
                word.clear();
            }
        }
        
        return (pIdx == P);
    }
};