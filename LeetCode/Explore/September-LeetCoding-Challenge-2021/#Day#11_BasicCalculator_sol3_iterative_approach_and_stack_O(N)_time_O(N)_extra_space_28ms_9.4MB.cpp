class Solution {
public:
    int calculate(string initialStr) {
        string s;
        for(char c: initialStr){
            if(c != ' '){
                s += c;
            }
        }
        
        s = "(" + s + ")";
        
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
                if(idx == 0 || s[idx - 1] == '('){
                    operatorStack.push('+');
                }
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
                if(s[idx - 1] == '('){
                    operatorStack.push('+');
                }
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