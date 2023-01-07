class Solution {
public:
    bool wordPattern(string pattern, string s) {
        const int P = pattern.length();
        const int A = 26;

        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        int pPos = 0;
        int wordStartPos = 0;
        for(int pos = 0; pos <= (int)s.length() && pPos < P; ++pos){
            if(pos == (int)s.length() || s[pos] == ' '){
                string word = s.substr(wordStartPos, pos - wordStartPos);
                wordStartPos = pos + 1;
                if((!charToWord.count(pattern[pPos]) && !wordToChar.count(word)) ||
                   (charToWord[pattern[pPos]] == word && wordToChar[word] == pattern[pPos])){
                       charToWord[pattern[pPos]] = word;
                       wordToChar[word] = pattern[pPos];
                       pPos += 1;
                }else{
                    return false;
                }
            }
        }

        return (pPos == P && wordStartPos == (int)s.length() + 1);
    }
};