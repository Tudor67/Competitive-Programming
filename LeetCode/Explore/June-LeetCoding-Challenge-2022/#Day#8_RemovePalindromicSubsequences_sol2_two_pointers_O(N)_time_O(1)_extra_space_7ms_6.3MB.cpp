class Solution {
private:
    bool isPalindrome(const string& S){
        int i = 0;
        int j = (int)S.length() - 1;
        while(i < j){
            if(S[i] == S[j]){
                i += 1;
                j -= 1;
            }else{
                return false;
            }
        }
        return true;
    }
    
public:
    int removePalindromeSub(string s) {
        if(isPalindrome(s)){
            return 1;
        }
        return 2;
    }
};