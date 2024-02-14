class Solution {
private:
    bool isPalindrome(const string& S){
        for(int i = 0, j = (int)S.length() - 1; i < j; ++i, --j){
            if(S[i] != S[j]){
                return false;
            }
        }
        return true;
    }

public:
    string firstPalindrome(vector<string>& words) {
        for(const string& WORD: words){
            if(isPalindrome(WORD)){
                return WORD;
            }
        }
        return "";
    }
};