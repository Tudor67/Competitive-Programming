class Solution {
public:
    int scoreOfParentheses(string S) {
        const int N = S.length();
        vector<int> score(N, 0);
        stack<int> st;
        for(int r = 0; r < N; ++r){
            if(S[r] == '('){
                st.push(r);
            }else{
                int l = st.top();
                st.pop();
                if(l + 1 == r){
                    score[l] = 1;
                }else{
                    score[l] = 2 * accumulate(score.begin() + l + 1, score.begin() + r, 0);
                    fill(score.begin() + l + 1, score.begin() + r, 0);
                }
            }
        }
        return accumulate(score.begin(), score.end(), 0);
    }
};