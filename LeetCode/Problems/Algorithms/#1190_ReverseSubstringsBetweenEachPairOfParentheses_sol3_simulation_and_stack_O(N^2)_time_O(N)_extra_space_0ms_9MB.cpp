class Solution {
public:
    string reverseParentheses(string s) {
        const int N = s.length();

        stack<int> st;
        for(int i = 0; i < N; ++i){
            if(s[i] == '('){
                st.push(i);
            }else if(s[i] == ')'){
                int startIndex = st.top();
                st.pop();
                reverse(s.begin() + startIndex + 1, s.begin() + i);
            }
        }

        string res;
        for(char c: s){
            if(c != '(' && c != ')'){
                res += c;
            }
        }

        return res;
    }
};