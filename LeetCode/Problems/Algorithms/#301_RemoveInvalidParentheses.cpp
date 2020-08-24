class Solution {
private:
    void back(int k, int op_par, int cl_par, int total_par, string& st, bool& check_unique,
              const string& s, int start_idx, vector<string>& answer){
        if(k == st.length()){
            answer.push_back(st);
        }
        else{
            for(int idx = start_idx; idx < (int)s.length(); ++idx){
                bool ok = (check_unique ? s[idx] != st[k] : true);
                if(!ok){
                    continue;
                }
                
                // Case 1: (
                if(s[idx] == '('){
                    if(op_par < total_par / 2){
                        st[k] = '(';
                        check_unique = false;
                        back(k + 1, op_par + 1, cl_par, total_par, st, check_unique, s, idx + 1, answer);
                        check_unique = true;
                    }
                }
                // Case 2: )
                else if(s[idx] == ')'){
                    if(op_par > cl_par){
                        st[k] = ')';
                        check_unique = false;
                        back(k + 1, op_par, cl_par + 1, total_par, st, check_unique, s, idx + 1, answer);
                        check_unique = true;
                    }
                }
                // Case 3
                else if(s[idx] != '(' && s[idx] != ')'){
                    st[k] = s[idx];
                    check_unique = false;
                    back(k + 1, op_par, cl_par, total_par, st, check_unique, s, idx + 1, answer);
                    check_unique = true;
                }
            }
        }
    }
    
public:
    vector<string> removeInvalidParentheses(string s) {
        int char_cnt = 0;
        int par_cnt = 0;
        int op_par = 0;
        for(char c: s){
            if(c == '('){
                op_par += 1;
            }
            else if(c == ')' && op_par > 0){
                op_par -= 1;
                par_cnt += 2;
            }
            else if(c != '(' && c != ')'){
                char_cnt += 1;
            }
        }
        
        int max_len = char_cnt + par_cnt;
        string st(max_len, '.');
        bool check_unique = false;
        vector<string> answer;
        
        back(0, 0, 0, par_cnt, st, check_unique, s, 0, answer);
        
        return answer;
    }
};