class Solution {
public:
    string removeOuterParentheses(string s) {
        const int N = s.length();

        vector<bool> isOut(N, false);
        stack<int> st;
        for(int i = 0; i < N; ++i){
            if(s[i] == '('){
                st.push(i);
            }else{
                if((int)st.size() == 1){
                    isOut[st.top()] = true;
                    isOut[i] = true;
                }
                st.pop();
            }
        }

        string res;
        for(int i = 0; i < N; ++i){
            if(!isOut[i]){
                res += s[i];
            }
        }

        return res;
    }
};