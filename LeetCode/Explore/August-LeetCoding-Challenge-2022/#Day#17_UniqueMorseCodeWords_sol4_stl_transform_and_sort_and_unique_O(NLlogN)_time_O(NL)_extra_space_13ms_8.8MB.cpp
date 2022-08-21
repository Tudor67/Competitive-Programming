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
        vector<string> morseCodes;
        transform(words.begin(), words.end(), back_inserter(morseCodes), wordToMorse);
        
        sort(morseCodes.begin(), morseCodes.end());
        morseCodes.resize(unique(morseCodes.begin(), morseCodes.end()) - morseCodes.begin());
        
        return morseCodes.size();
    }
};