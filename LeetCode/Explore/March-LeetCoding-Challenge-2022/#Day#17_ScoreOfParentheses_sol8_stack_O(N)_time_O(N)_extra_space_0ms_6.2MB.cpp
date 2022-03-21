class Solution {
public:
    int scoreOfParentheses(string s) {
        const int N = s.length();
        
        int score = 0;
        stack<pair<int, int>> st;
        for(int i = 0; i < N; ++i){
            if(s[i] == '('){
                if(st.empty()){
                    st.emplace(i, 1);
                }else{
                    st.emplace(i, st.top().second * 2);
                }
            }else{
                if(st.top().first + 1 == i){
                    score += st.top().second;
                }
                st.pop();
            }
        }
        
        return score;
    }
};