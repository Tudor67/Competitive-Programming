class Solution {
private:
    int evaluate(vector<string>& tokens, int& pos){
        if(tokens[pos] == "+" || tokens[pos] == "-" || tokens[pos] == "*" || tokens[pos] == "/"){
            char currentOperator = tokens[pos][0];
            int num2 = evaluate(tokens, --pos);
            int num1 = evaluate(tokens, --pos);
            if(currentOperator == '+'){
                return num1 + num2;
            }else if(currentOperator == '-'){
                return num1 - num2;
            }else if(currentOperator == '*'){
                return num1 * num2;
            }else if(currentOperator == '/'){
                return num1 / num2;
            }
        }
        return stoi(tokens[pos]);
    }
    
public:
    int evalRPN(vector<string>& tokens) {
        int pos = (int)tokens.size() - 1;
        return evaluate(tokens, pos);
    }
};