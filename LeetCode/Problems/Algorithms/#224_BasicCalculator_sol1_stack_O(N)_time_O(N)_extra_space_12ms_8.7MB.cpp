class Solution {
public:
    int calculate(string initialStr) {
        string s;
        for(char c: initialStr){
            if(c != ' '){
                s += c;
            }
        }
        
        const int N = s.length();
        vector<bool> flip(N, false);
        stack<int> st;
        for(int i = 0; i < N; ++i){
            if(s[i] == '('){
                st.push(i);
            }else if(s[i] == ')'){
                if(st.top() > 0 && s[st.top() - 1] == '-'){
                    flip[i] = true;
                    flip[st.top()] = true;
                }
                st.pop();
            }
        }
        
        int sum = 0;
        int sign = 1;
        int currentSign = 1;
        int currentNum = 0;
        for(int i = 0; i < N; ++i){
            if(s[i] == '(' || s[i] == ')'){
                sum += sign * currentSign * currentNum;
                sign *= (flip[i] ? -1 : 1);
                currentSign = 1;
                currentNum = 0;
            }else if(s[i] == '-' || s[i] == '+'){
                sum += sign * currentSign * currentNum;
                currentSign = (s[i] == '-' ? -1 : 1);
                currentNum = 0;
            }else{
                currentNum = 10 * currentNum + (s[i] - '0');
            }
        }
        
        sum += sign * currentSign * currentNum;
        
        return sum;
    }
};