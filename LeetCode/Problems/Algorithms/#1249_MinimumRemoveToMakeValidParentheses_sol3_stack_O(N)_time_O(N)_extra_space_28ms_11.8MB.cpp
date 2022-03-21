class Solution {
public:
    string minRemoveToMakeValid(string s) {
        const int N = s.length();
        
        vector<bool> isValid(N, true);
        stack<int> st;
        for(int i = 0; i < N; ++i){
            if(s[i] == '('){
                st.push(i);
            }else if(s[i] == ')'){
                if(st.empty()){
                    isValid[i] = false;
                }else{
                    st.pop();
                }
            }
        }
        
        while(!st.empty()){
            isValid[st.top()] = false;
            st.pop();
        }
        
        string res;
        for(int i = 0; i < N; ++i){
            if(isValid[i]){
                res += s[i];
            }
        }
        
        return res;
    }
};