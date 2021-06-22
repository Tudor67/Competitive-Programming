class Solution {
private:
    void back(int op, int cl, string& st, const int& N, vector<string>& parentheses){
        if(op + cl == 2 * N){
            parentheses.push_back(st);
        }else{
            if(op < N){
                st.push_back('(');
                back(op + 1, cl, st, N, parentheses);
                st.pop_back();
            }
            if(cl < op){
                st.push_back(')');
                back(op, cl + 1, st, N, parentheses);
                st.pop_back();
            }
        }
    }
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> parentheses;
        string st;
        back(0, 0, st, n, parentheses);
        return parentheses;
    }
};