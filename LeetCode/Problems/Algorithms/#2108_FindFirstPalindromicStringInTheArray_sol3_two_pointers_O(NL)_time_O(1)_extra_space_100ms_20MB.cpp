class Solution {
private:
    bool isPalindrome(const string& WORD){
        const int L = WORD.length();
        for(int i = 0, j = L - 1; i < j; ++i, --j){
            if(WORD[i] != WORD[j]){
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