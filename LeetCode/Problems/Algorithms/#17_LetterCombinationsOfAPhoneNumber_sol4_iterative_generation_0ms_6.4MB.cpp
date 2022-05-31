class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        
        static const vector<string> LETTERS = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res = {""};
        for(char digit: digits){
            vector<string> currentCombinations;
            for(string& s: res){
                for(char letter: LETTERS[digit - '0']){
                    currentCombinations.push_back(s + letter);
                }
            }
            res = currentCombinations;
        }
        
        return res;
    }
};