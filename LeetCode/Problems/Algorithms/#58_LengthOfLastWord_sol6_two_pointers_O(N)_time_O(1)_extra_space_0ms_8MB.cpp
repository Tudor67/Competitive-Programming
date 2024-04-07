class Solution {
public:
    int lengthOfLastWord(string s) {
        const int N = s.length();

        int lastWordLen = 0;
        
        int i = N - 1;
        while(i >= 0 && s[i] == ' '){
            i -= 1;
        }

        while(i >= 0 && s[i] != ' '){
            lastWordLen += 1;
            i -= 1;
        }

        return lastWordLen;
    }
};