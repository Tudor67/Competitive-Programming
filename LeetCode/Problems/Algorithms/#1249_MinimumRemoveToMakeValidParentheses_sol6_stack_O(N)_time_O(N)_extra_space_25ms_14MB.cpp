class Solution {
public:
    string minRemoveToMakeValid(string s) {
        const int N = s.length();

        vector<bool> keep(N, true);
        stack<int> st;
        for(int i = 0; i < N; ++i){
            if(s[i] == '('){
                st.push(i);
            }else if(s[i] == ')'){
                if(st.empty()){
                    keep[i] = false;
                }else{
                    st.pop();
                }
            }
        }

        while(!st.empty()){
            int i = st.top();
            st.pop();

            keep[i] = false;
        }

        string res;
        for(int i = 0; i < N; ++i){
            if(keep[i]){
                res += s[i];
            }
        }

        return res;
    }
};