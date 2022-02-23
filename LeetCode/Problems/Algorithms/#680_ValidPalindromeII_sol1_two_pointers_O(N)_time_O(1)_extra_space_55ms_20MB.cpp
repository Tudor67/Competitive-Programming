class Solution {
private:
    bool isPalindrome(const string& S, int badPos){
        const int N = S.length();
        int i = 0;
        int j = N - 1;
        while(i < j){
            if(i == badPos){
                ++i;
            }else if(j == badPos){
                --j;
            }else if(S[i] == S[j]){
                ++i;
                --j;
            }else{
                return false;
            }
        }
        return true;
    }
    
public:
    bool validPalindrome(string s) {
        const int N = s.length();
        
        int badPos1 = -1;
        int badPos2 = -1;
        int i = 0;
        int j = N - 1;
        while(i < j && badPos1 == -1 && badPos2 == -1){
            if(s[i] == s[j]){
                ++i;
                --j;
            }else{
                badPos1 = i;
                badPos2 = j;
            }
        }
        
        return isPalindrome(s, -1) ||
               isPalindrome(s, badPos1) ||
               isPalindrome(s, badPos2);
    }
};