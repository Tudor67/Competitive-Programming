class Solution {
public:
    int longestValidParentheses(string s) {
        const int N = s.length();
        
        vector<int> maxLenAt(N + 1, 0);
        
        stack<int> st;
        for(int i = 0; i < N; ++i){
            if(s[i] == '('){
                st.push(i);
            }else if(!st.empty()){
                int prevIdx = st.top();
                st.pop();
                
                int len = i - prevIdx + 1;
                if(prevIdx >= 1){
                    len += maxLenAt[prevIdx - 1];
                }
                
                maxLenAt[i] = len;
            }
        }
        
        return *max_element(maxLenAt.begin(), maxLenAt.end());
    }
};