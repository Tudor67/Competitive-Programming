class Solution {
private:
    string removeSpaces(const string& S){
        string res;
        for(char c: S){
            if(c != ' '){
                res += c;
            }
        }
        return res;
    }
    
    string addExtraPluses(const string& S){
        const int N = S.length();
        string res;
        for(int i = 0; i < N; ++i){
            if(i == 0 || S[i - 1] == '('){
                if(S[i] == '(' || isdigit(S[i])){
                    res += '+';
                }
            }
            res += S[i];
        }
        return res;
    }
    
public:
    int calculate(string s) {
        s = removeSpaces(s);
        s = "(" + s + ")";
        s = addExtraPluses(s);
        
        const int N = s.length();
        stack<int> operandStack;
        stack<char> operatorStack;
        operandStack.push(0);
        operatorStack.push('+');
        
        int idx = 0;
        while(idx < N){
            if(s[idx] == '-' || s[idx] == '+'){
                operatorStack.push(s[idx]);
                idx += 1;
            }else if(s[idx] == '('){
                operandStack.push(0);
                idx += 1;
            }else if(s[idx] == ')'){
                int num = operandStack.top();
                num = (operatorStack.top() == '-' ? -num : num);
                operandStack.pop();
                operatorStack.pop();
                operandStack.top() += num;
                idx += 1;
            }else{
                int num = 0;
                while(idx < N && isdigit(s[idx])){
                    num = num * 10 + (s[idx] - '0');
                    idx += 1;
                }
                num = (operatorStack.top() == '-' ? -num : num);
                operatorStack.pop();
                operandStack.top() += num;
            }
        }
        
        return operandStack.top();
    }
};