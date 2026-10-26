class Solution {
private:
    void solve(int i, int openPar, int closedPar, int totalPar, string& st, vector<string>& res, string& s){
        if(openPar + closedPar + (int)s.length() - i < totalPar){
            return;
        }
        
        if(i == (int)s.length()){
            if(openPar + closedPar == totalPar){
                res.push_back(st);
            }
            return;
        }

        if(s[i] == '('){
            // keep '('
            if(openPar < totalPar / 2){
                st.push_back(s[i]);
                solve(i + 1, openPar + 1, closedPar, totalPar, st, res, s);
                st.pop_back();
            }

            // remove '('
            solve(i + 1, openPar, closedPar, totalPar, st, res, s);
        }else if(s[i] == ')'){
            // keep ')'
            if(openPar > closedPar){
                st.push_back(s[i]);
                solve(i + 1, openPar, closedPar + 1, totalPar, st, res, s);
                st.pop_back();
            }

            // remove ')'
            solve(i + 1, openPar, closedPar, totalPar, st, res, s);
        }else{
            // keep the letter s[i]
            st.push_back(s[i]);
            solve(i + 1, openPar, closedPar, totalPar, st, res, s);
            st.pop_back();
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        int totalValidParentheses = 0;
        int balance = 0;
        for(char c: s){
            if(c == '('){
                balance += 1;
            }else if(c == ')' && balance >= 1){
                balance -= 1;
                totalValidParentheses += 2;
            }
        }

        string st;
        vector<string> res;
        solve(0, 0, 0, totalValidParentheses, st, res, s);

        unordered_set<string> resSet(res.begin(), res.end());
        return vector<string>(resSet.begin(), resSet.end());
    }
};