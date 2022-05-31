class Solution {
private:
    const vector<string> LETTERS = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void back(string& st, string& digits, vector<string>& res){
        if(st.length() == digits.length()){
            res.push_back(st);
        }else{
            int level = st.size();
            for(char letter: LETTERS[digits[level] - '0']){
                st.push_back(letter);
                back(st, digits, res);
                st.pop_back();
            }
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        string st;
        vector<string> res;
        back(st, digits, res);
        return res;
    }
};