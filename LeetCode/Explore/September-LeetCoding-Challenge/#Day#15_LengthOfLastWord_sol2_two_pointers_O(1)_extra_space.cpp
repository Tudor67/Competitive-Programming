class Solution {
public:
    int lengthOfLastWord(string s) {
        int lastWordEnd = (int)s.length() - 1;
        while(lastWordEnd > 0 && s[lastWordEnd] == ' '){
            lastWordEnd -= 1;
        }
        
        int lastWordBegin = lastWordEnd;
        while(lastWordBegin >= 0 && s[lastWordBegin] != ' '){
            lastWordBegin -= 1;
        }
        
        return (lastWordEnd - lastWordBegin);
    }
};