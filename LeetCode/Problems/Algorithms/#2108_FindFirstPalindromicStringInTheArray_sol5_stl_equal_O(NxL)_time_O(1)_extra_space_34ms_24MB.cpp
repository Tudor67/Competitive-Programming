class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(const string& WORD: words){
            if(equal(WORD.begin(), WORD.end(), WORD.rbegin())){
                return WORD;
            }
        }
        return "";
    }
};