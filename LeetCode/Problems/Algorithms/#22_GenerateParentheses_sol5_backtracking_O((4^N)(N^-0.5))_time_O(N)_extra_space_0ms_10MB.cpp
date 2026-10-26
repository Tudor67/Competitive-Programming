class Solution {
private:
    void generateParentheses(int level, int openParentheses, int closedParentheses, int totalParentheses,
                             string& st, vector<string>& res){
        if(level == totalParentheses){
            res.push_back(st);
        }else{
            if(openParentheses < totalParentheses / 2){
                st[level] = '(';
                generateParentheses(level + 1, openParentheses + 1, closedParentheses, totalParentheses, st, res);
            }
            if(openParentheses > closedParentheses){
                st[level] = ')';
                generateParentheses(level + 1, openParentheses, closedParentheses + 1, totalParentheses, st, res);
            }
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        string st(2 * n, '#');
        vector<string> res;
        generateParentheses(0, 0, 0, 2 * n, st, res);
        return res;
    }
};