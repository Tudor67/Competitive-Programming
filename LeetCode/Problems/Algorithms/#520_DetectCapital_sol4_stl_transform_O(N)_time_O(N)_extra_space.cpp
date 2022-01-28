class Solution {
public:
    bool detectCapitalUse(string word) {
        string word1 = word;
        transform(word.begin(), word.end(), word1.begin(), ::toupper);
        
        string word2 = word;
        transform(word.begin(), word.end(), word2.begin(), ::tolower);
        
        string word3 = word;
        transform(word.begin(), word.end(), word3.begin(), ::tolower);
        word3[0] = toupper(word[0]);
        
        return (word1 == word || word2 == word || word3 == word);
    }
};