class Solution {
public:
    bool strongPasswordCheckerII(string s) {
        const int N = s.length();
        const string SPECIAL_CHARS = "!@#$%^&*()-+";
        const unordered_set<char> SPECIAL_CHARS_SET(SPECIAL_CHARS.begin(), SPECIAL_CHARS.end());
        
        bool validLength = (N >= 8);
        bool containsLower = false;
        bool containsUpper = false;
        bool containsDigit = false;
        bool containsSpecial = false;
        bool distinctAdjacentChars = true;
        for(int i = 0; i < N; ++i){
            if(islower(s[i])){
                containsLower = true;
            }else if(isupper(s[i])){
                containsUpper = true;
            }else if(isdigit(s[i])){
                containsDigit = true;
            }else if(SPECIAL_CHARS_SET.count(s[i])){
                containsSpecial = true;
            }
            if(i > 0 && s[i - 1] == s[i]){
                distinctAdjacentChars = false;
            }
        }
        
        return (validLength &&
                containsLower && containsUpper && containsDigit && containsSpecial &&
                distinctAdjacentChars);
    }
};