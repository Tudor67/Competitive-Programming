class Solution {
public:
    int longestValidParentheses(string s) {
        const int N = s.length();

        vector<bool> isValid(N, false);
        stack<int> st;
        for(int i = 0; i < N; ++i){
            if(s[i] == '('){
                st.push(i);
            }else if(!st.empty()){
                isValid[i] = true;
                isValid[st.top()] = true;
                st.pop();
            }
        }

        int maxValidLen = 0;
        int currLen = 0;
        for(int i = 0; i < N; ++i){
            if(isValid[i]){
                ++currLen;
                maxValidLen = max(maxValidLen, currLen);
            }else{
                currLen = 0;
            }
        }

        return maxValidLen;
    }
};