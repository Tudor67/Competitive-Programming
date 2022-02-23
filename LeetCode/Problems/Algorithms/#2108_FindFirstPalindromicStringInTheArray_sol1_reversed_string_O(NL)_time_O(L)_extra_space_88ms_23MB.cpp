class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(string& word: words){
            if(word == string(word.rbegin(), word.rend())){
                return word;
            }
        }
        return "";
    }
};