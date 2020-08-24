class Solution {
public:
    int longestValidParentheses(string s) {
        const int N = s.length();
        
        int answer = 0;
        for(int reversed = 0; reversed <= 1; ++reversed){
            int opened = 0;
            int closed = 0;
            
            for(char c: s){
                if((c == '(' && !reversed) || (c == ')' && reversed)){
                    opened += 1;
                }else{
                    closed += 1;
                }
                
                if(opened < closed){
                    opened = 0;
                    closed = 0;
                }else if(opened == closed){
                    answer = max(opened + closed, answer);
                }
            }
            
            reverse(s.begin(), s.end());
        }
        
        return answer;
    }
};