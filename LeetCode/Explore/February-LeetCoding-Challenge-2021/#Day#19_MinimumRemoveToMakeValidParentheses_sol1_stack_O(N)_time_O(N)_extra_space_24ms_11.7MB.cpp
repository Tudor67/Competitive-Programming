class Solution {
public:
    string minRemoveToMakeValid(string s) {
        const int N = s.length();
        
        vector<bool> isOk(N, true);
        stack<int> st;
        for(int i = 0; i < N; ++i){
            if(s[i] == '('){
                st.push(i);
            }else if(s[i] == ')'){
                if(st.empty()){
                    isOk[i] = false;
                }else{
                    st.pop();
                }
            }
        }
        
        while(!st.empty()){
            int pos = st.top();
            st.pop();
            isOk[pos] = false;
        }
        
        string answer;
        for(int i = 0; i < N; ++i){
            if(isOk[i]){
                answer += s[i];
            }
        }
        
        return answer;
    }
};