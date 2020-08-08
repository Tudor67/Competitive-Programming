class Solution {
public:
    bool isPalindrome(string s) {
        const int N = s.length();
        
        int i = 0;
        int j = N - 1;
        while(i < j){
            while(i < j && !isalnum(s[i])){
                i += 1;
            }
            
            while(i < j && !isalnum(s[j])){
                j -= 1;
            }
            
            if(tolower(s[i]) == tolower(s[j])){
                i += 1;
                j -= 1;
            }else{
                return false;
            }
        }
        
        return true;
    }
};