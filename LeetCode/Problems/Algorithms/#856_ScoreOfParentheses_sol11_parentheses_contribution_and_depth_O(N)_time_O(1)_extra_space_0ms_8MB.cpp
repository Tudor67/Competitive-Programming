class Solution {
public:
    int scoreOfParentheses(string s) {
        const int N = s.length();

        int score = 0;
        int depth = 0;

        for(int i = 0; i < N; ++i){
            if(s[i] == '('){
                depth += 1;
            }else{
                depth -= 1;
                if(s[i - 1] == '('){
                    score += (1 << depth);
                }
            }
        }

        return score;
    }
};