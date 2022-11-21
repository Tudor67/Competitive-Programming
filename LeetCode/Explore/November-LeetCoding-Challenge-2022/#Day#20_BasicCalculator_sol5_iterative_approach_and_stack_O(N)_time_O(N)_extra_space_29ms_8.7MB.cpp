class Solution {
public:
    int calculate(string s) {
        s = "(" + s + ")";
        
        int res = 0;
        int currentNum = 0;
        int currentSign = 1;
        
        stack<int> levelSignSt;
        levelSignSt.push(1);
        for(char c: s){
            if(c == '('){
                res += levelSignSt.top() * currentSign * currentNum;
                levelSignSt.push(levelSignSt.top() * currentSign);
                currentNum = 0;
                currentSign = 1;
            }else if(c == ')'){
                res += levelSignSt.top() * currentSign * currentNum;
                levelSignSt.pop();
                currentNum = 0;
                currentSign = 1;
            }else if(c == '+'){
                res += levelSignSt.top() * currentSign * currentNum;
                currentNum = 0;
                currentSign = 1;
            }else if(c == '-'){
                res += levelSignSt.top() * currentSign * currentNum;
                currentNum = 0;
                currentSign = -1;
            }else if(isdigit(c)){
                currentNum = currentNum * 10 + (c - '0');
            }
        }
        
        return res;
    }
};