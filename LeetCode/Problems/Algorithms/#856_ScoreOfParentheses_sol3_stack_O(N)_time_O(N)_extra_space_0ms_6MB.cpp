class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> st;
        st.push(0);
        for(char c: S){
            if(c == '('){
                st.push(0);
            }else{
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b + max(1, 2 * a));
            }
        }
        return st.top();
    }
};