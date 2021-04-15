class Solution {
private:
    const vector<string> LETTERS = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void back(int level, string& st, const string& DIGITS, vector<string>& answer){
        if(level == (int)DIGITS.length()){
            if(!st.empty()){
                answer.push_back(st);
            }
        }else{
            for(char c: LETTERS[DIGITS[level] - '0']){
                st.push_back(c);
                back(level + 1, st, DIGITS, answer);
                st.pop_back();
            }
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        string st;
        vector<string> answer;
        back(0, st, digits, answer);
        return answer;
    }
};