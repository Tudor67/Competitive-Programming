class Solution {
public:
    int scoreOfParentheses(string s) {
        const int N = s.length();

        vector<int> multCoef(N, 1);
        vector<int> divCoef(N, 1);
        stack<int> st;

        for(int i = 0; i < N; ++i){
            if(s[i] == '('){
                st.push(i);
            }else{
                if(i - st.top() > 1){
                    multCoef[st.top()] = 2;
                    divCoef[i] = 2;
                }
                st.pop();
            }
        }

        int score = 0;
        int contrib = multCoef[0];
        for(int i = 1; i < N; ++i){
            contrib *= multCoef[i];
            contrib /= divCoef[i];
            if(s[i - 1] == '(' && s[i] == ')'){
                score += contrib;
            }
        }

        return score;
    }
};