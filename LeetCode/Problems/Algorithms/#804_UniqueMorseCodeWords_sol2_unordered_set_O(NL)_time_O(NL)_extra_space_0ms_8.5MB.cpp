class Solution {
private:
    static string wordToMorse(const string& WORD){
        static const vector<string> MORSE_CODE_OF = {
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--",
            "-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
        };
        
        string morseCode;
        for(char c: WORD){
            morseCode += MORSE_CODE_OF[c - 'a'];
        }
        
        return morseCode;
    }
    
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> morseCodeSet;
        
        for(const string& WORD: words){
            morseCodeSet.insert(wordToMorse(WORD));
        }
        
        return morseCodeSet.size();
    }
};