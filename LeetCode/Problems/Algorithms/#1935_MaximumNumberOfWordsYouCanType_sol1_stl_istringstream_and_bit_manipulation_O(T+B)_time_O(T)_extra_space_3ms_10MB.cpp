class Solution {
private:
    int stringToBitMask(string s){
        int mask = 0;
        for(char c: s){
            mask |= (1 << (c - 'a'));
        }
        return mask;
    }

public:
    int canBeTypedWords(string text, string brokenLetters) {
        int validWords = 0;

        istringstream iss(text);
        string s;
        int brokenMask = stringToBitMask(brokenLetters);

        while(iss >> s){
            if((stringToBitMask(s) & brokenMask) == 0){
                validWords += 1;
            }
        }

        return validWords;
    }
};