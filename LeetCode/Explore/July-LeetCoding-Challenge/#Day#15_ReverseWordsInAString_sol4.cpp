class Solution {
public:
    string reverseWords(string s) {
        // Step 1: remove leading and trailing spaces
        int p1 = 0;
        int p2 = (int)s.size() - 1;
        for(; p1 <= p2 && s[p1] == ' '; ++p1);
        for(; p1 <= p2 && s[p2] == ' '; --p2);
        for(int i = p1; i < s.size(); ++i){
            s[i - p1] = s[i];
        }
        s.resize(p2 - p1 + 1);
        
        // Step 2: remove consecutive spaces between words
        p1 = 0;
        p2 = 0;
        for(p1 = 0, p2 = 0; p2 < s.size(); ++p2){
            if(p2 + 1 < s.size() && s[p2] == ' ' && s[p2 + 1] == ' '){
                // ignore consecutive spaces
                continue;
            }else{
                s[p1] = s[p2];
                ++p1;
            }
        }
        s.resize(p1);
        
        // Step 3: reverse s
        for(int i = 0, j = (int)s.size() - 1; i < j; ++i, --j){
            swap(s[i], s[j]);
        }
        
        // Step 4: reverse each word of s
        for(int i = 0, j = 0; j <= s.size(); ++j){
            if(j == s.size() || s[j] == ' '){
                for(int p1 = i, p2 = j - 1; p1 < p2; ++p1, --p2){
                    swap(s[p1], s[p2]);
                }
                i = j + 1;
            }
        }
        
        return s;
    }
};