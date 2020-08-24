class Solution {
public:
    int longestValidParentheses(string s) {
        const int N = s.length();
        
        vector<bool> ok(N + 1, false);
        stack<int> st;
        for(int i = 0; i < N; ++i){
            if(s[i] == '('){
                st.push(i);
            }else if(s[i] == ')' && !st.empty()){
                ok[i] = true;
                ok[st.top()] = true;
                st.pop();
            }
        }
        
        int max_len = 0;
        for(int i = 0, len = 0; i <= N; ++i){
            if(ok[i]){
                len += 1;
            }else{
                max_len = max(len, max_len);
                len = 0;
            }
        }
        
        return max_len;
    }
};