class Solution {
public:
    int scoreOfParentheses(string S) {
        int answer = 0;
        int openedParentheses = 0;
        for(int i = 0; i < (int)S.length(); ++i){
            if(S[i] == '('){
                openedParentheses += 1;
            }else{
                openedParentheses -= 1;
                if(S[i - 1] == '('){
                    answer += (1 << openedParentheses);
                }
            }
        }
        return answer;
    }
};