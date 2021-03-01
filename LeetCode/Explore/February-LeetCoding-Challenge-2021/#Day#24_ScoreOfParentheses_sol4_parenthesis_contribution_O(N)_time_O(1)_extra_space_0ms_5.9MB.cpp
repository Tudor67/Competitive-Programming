class Solution {
public:
    int scoreOfParentheses(string S) {
        int answer = 0;
        int contrib = 0;
        for(int i = 0; i < (int)S.length(); ++i){
            if(S[i] == '('){
                if(contrib == 0){
                    contrib = 1;
                }else{
                    contrib *= 2;
                }
            }else if(S[i] == ')'){
                if(S[i - 1] == '('){
                    answer += contrib;
                    contrib /= 2;
                }else if(S[i - 1] = ')'){
                    contrib /= 2;
                }
            }
        }
        return answer;
    }
};