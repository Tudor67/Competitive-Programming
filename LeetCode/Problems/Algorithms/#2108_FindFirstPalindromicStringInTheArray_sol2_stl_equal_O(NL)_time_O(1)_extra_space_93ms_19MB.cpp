class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(string& word: words){
            if(equal(word.rbegin(), word.rend(), word.begin())){
                return word;
            }
        }
        return "";
    }
};