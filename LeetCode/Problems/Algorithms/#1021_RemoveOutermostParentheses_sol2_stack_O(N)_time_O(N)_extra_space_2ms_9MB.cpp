class Solution {
public:
    string removeOuterParentheses(string s) {
        const int N = s.length();

        string res;
        stack<int> st;
        for(int i = 0; i < N; ++i){
            if(s[i] == '('){
                st.push(i);
            }else{
                if((int)st.size() == 1){
                    res.append(s, st.top() + 1, i - st.top() - 1);
                }
                st.pop();
            }
        }

        return res;
    }
};