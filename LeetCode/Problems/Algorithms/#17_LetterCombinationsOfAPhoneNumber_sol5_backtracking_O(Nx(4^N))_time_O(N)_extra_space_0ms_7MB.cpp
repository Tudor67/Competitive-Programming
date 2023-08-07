class Solution {
private:
    const vector<string> DIGIT_TO_LETTERS = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void back(int level, string& digits, string& combination, vector<string>& combinations){
        if(level == (int)digits.length()){
            if(!combination.empty()){
                combinations.push_back(combination);
            }
        }else{
            for(char c: DIGIT_TO_LETTERS[digits[level] - '0']){
                combination.push_back(c);
                back(level + 1, digits, combination, combinations);
                combination.pop_back();
            }
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        string combination;
        vector<string> combinations;
        back(0, digits, combination, combinations);
        return combinations;
    }
};