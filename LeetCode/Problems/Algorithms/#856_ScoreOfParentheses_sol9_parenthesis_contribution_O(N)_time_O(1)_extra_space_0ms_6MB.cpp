class Solution {
public:
    int scoreOfParentheses(string s) {
        const int N = s.length();
        
        int score = 0;
        int bal = 0;
        for(int i = 0; i + 1 < N; ++i){
            if(s[i] == '('){
                if(s[i + 1] == ')'){
                    score += (1 << bal);
                }
                bal += 1;
            }else{
                bal -= 1;
            }
        }
        
        return score;
    }
};