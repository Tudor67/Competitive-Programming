class Solution {
public:
    int lengthOfLastWord(string s) {
        int lastWordLength = 0;
        for(int i = 0, j = 0; j <= s.length(); ++j){
            if(j == s.length() || s[j] == ' '){
                if(i < j){
                    lastWordLength = j - i;
                }
                i = j + 1;
            }
        }
        return lastWordLength;
    }
};