class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        static const vector<string> LETTER_CODE = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> wordCodes;
        for(const string& WORD: words){
            string wordCode;
            for(const char& LETTER: WORD){
                wordCode += LETTER_CODE[LETTER - 'a'];
            }
            wordCodes.insert(wordCode);
        }
        
        return wordCodes.size();
    }
};