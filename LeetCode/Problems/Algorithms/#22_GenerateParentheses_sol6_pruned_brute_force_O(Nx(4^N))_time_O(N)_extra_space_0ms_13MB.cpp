class Solution {
private:
    void generateParentheses(int balance, int totalParentheses, string& st, vector<string>& res){
        if((int)st.length() == totalParentheses){
            if(balance == 0){
                res.push_back(st);
            }
            return;
        }

        st.push_back('(');
        generateParentheses(balance + 1, totalParentheses, st, res);
        st.pop_back();

        if(balance > 0){
            st.push_back(')');
            generateParentheses(balance - 1, totalParentheses, st, res);
            st.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        string st;
        vector<string> res;
        generateParentheses(0, 2 * n, st, res);
        return res;
    }
};