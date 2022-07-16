class Solution {
public:
    bool strongPasswordCheckerII(string s) {
        const int N = s.length();
        
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
            }else{
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