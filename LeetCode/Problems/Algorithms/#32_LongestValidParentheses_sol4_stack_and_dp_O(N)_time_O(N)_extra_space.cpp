class Solution {
public:
    int longestValidParentheses(string s) {
        const int N = s.length();
        
        s = "#" + s;
        
        // dp[i]: length of the longest valid parentheses substring that ends at position i
        vector<int> dp(N + 1, 0);
        stack<int> st;
        
        for(int i = 1; i <= N; ++i){
            if(s[i] == '('){
                st.push(i);
            }else{
                if(!st.empty()){
                    dp[i] = i - st.top() + 1 + dp[st.top() - 1];
                    st.pop();
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};