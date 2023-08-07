class Solution {
private:
    const vector<string> DIGIT_TO_LETTERS = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

public:
    vector<string> letterCombinations(string digits) {
        const int N = digits.size();
        
        vector<string> prevCombinations = {""};
        vector<string> curCombinations;
        for(char c: digits){
            curCombinations.clear();
            for(string& prevCombination: prevCombinations){
                for(char letter: DIGIT_TO_LETTERS[c - '0']){
                    curCombinations.push_back(prevCombination + letter);
                }
            }
            prevCombinations = curCombinations;
        }

        return curCombinations;
    }
};