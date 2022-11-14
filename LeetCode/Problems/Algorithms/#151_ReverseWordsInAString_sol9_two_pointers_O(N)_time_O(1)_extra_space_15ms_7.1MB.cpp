class Solution {
public:
    string reverseWords(string s) {
        // Step 1: remove redundant spaces
        int len = 0;
        for(int i = 0; i < (int)s.length(); ++i){
            if(s[i] != ' ' || (i >= 1 && s[i - 1] != ' ')){
                len += 1;
                s[len - 1] = s[i];
            }
        }
        if(s[len - 1] == ' '){
            len -= 1;
        }
        s.resize(len);
        
        // Step 2: reverse s
        reverse(s.begin(), s.end());
        
        // Step 3: reverse words
        int startPos = 0;
        for(int i = 0; i < len; ++i){
            if(i == len - 1 || s[i + 1] == ' '){
                reverse(s.begin() + startPos, s.begin() + i + 1);
                startPos = i + 2;
            }
        }
        
        return s;
    }
};