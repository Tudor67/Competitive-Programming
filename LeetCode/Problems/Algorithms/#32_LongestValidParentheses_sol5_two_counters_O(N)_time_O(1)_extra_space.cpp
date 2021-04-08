class Solution {
public:
    int longestValidParentheses(string s) {
        const int N = s.length();
        int answer = 0;
        
        // from left to right
        for(int i = 0, open = 0, closed = 0; i < N; ++i){
            if(s[i] == '('){
                open += 1;
            }else{
                closed += 1;
                if(open == closed){
                    answer = max(2 * open, answer);
                }else if(open < closed){
                    open = 0;
                    closed = 0;
                }
            }
        }
        
        // from right to left (we move backward)
        // ')' is considered open parenthesis and '(' is considered closed parenthesis
        for(int i = N - 1, open = 0, closed = 0; i >= 0; --i){
            if(s[i] == ')'){
                open += 1; 
            }else{
                closed += 1;
                if(open == closed){
                    answer = max(2 * open, answer);
                }else if(open < closed){
                    open = 0;
                    closed = 0;
                }
            }
        }
        
        return answer;
    }
};