class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int brokenMask = 0;
        for(char c: brokenLetters){
            brokenMask |= (1 << (c - 'a'));
        }

        int validWords = 0;
        int wordMask = 0;
        for(int i = 0; i < (int)text.length(); ++i){
            if(text[i] != ' '){
                wordMask |= (1 << (text[i] - 'a'));
            }
            if(i + 1 == (int)text.length() || text[i + 1] == ' '){
                if((wordMask & brokenMask) == 0){
                    validWords += 1;
                }
                wordMask = 0;
            }
        }

        return validWords;
    }
};