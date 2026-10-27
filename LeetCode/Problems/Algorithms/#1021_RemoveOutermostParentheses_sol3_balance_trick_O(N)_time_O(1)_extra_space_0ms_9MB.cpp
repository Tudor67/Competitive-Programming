class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;

        int balance = 0;
        for(char c: s){
            if(c == '('){
                balance += 1;
            }else{
                balance -= 1;
            }

            bool isOut = (c == '(' && balance == 1) ||
                         (c == ')' && balance == 0);

            if(!isOut){
                res += c;
            }
        }

        return res;
    }
};