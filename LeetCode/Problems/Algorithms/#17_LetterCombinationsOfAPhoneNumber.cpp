class Solution {
private:
    const vector<string> letters_from = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void back(int k, string& st, vector<string>& solutions, const string& digits){
        if(k == st.length()){
            solutions.push_back(st);
        }else{
            for(char c: letters_from[digits[k] - '0']){
                st[k] = c;
                back(k + 1, st, solutions, digits);
            }
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        vector<string> solutions;
        
        if(digits.length() > 0){
            string st(digits.length(), '.');
            back(0, st, solutions, digits);
        }
        
        return solutions;
    }
};