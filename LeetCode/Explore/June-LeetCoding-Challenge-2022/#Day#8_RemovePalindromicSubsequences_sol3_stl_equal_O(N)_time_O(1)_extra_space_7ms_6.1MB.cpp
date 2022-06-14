class Solution {
private:
    bool isPalindrome(const string& S){
        return equal(S.begin(), S.end(), S.rbegin());
    }
    
public:
    int removePalindromeSub(string s) {
        if(isPalindrome(s)){
            return 1;
        }
        return 2;
    }
};