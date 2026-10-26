class Solution {
private:
    void solve(int i, int balance, string& st, int& minRemovals, vector<string>& res, string& s){
        int currRemovals = i - (int)st.length();
        if(minRemovals < currRemovals){
            return;
        }

        if(i == (int)s.length()){
            if(balance != 0){
                return;
            }
            if(minRemovals > currRemovals){
                minRemovals = currRemovals;
                res.clear();
            }
            if(minRemovals == currRemovals){
                res.push_back(st);
            }
            return;
        }

        if(s[i] == '('){
            // keep '('
            st.push_back(s[i]);
            solve(i + 1, balance + 1, st, minRemovals, res, s);
            st.pop_back();

            // remove '('
            solve(i + 1, balance, st, minRemovals, res, s);
        }else if(s[i] == ')'){
            // keep ')'
            if(balance >= 1){
                st.push_back(s[i]);
                solve(i + 1, balance - 1, st, minRemovals, res, s);
                st.pop_back();
            }

            // remove ')'
            solve(i + 1, balance, st, minRemovals, res, s);
        }else{
            // keep the letter s[i]
            st.push_back(s[i]);
            solve(i + 1, balance, st, minRemovals, res, s);
            st.pop_back();
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        string st;
        vector<string> res;
        int minRemovals = s.length();
        solve(0, 0, st, minRemovals, res, s);

        unordered_set<string> resSet(res.begin(), res.end());
        return vector<string>(resSet.begin(), resSet.end());
    }
};