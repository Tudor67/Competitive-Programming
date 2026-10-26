class Solution {
public:
    int minAddToMakeValid(string s) {
        int res = 0;
        int balance = 0;

        for(char c: s){
            if(c == '('){
                balance += 1;
            }else{
                balance -= 1;
            }
            
            if(balance < 0){
                balance = 0;
                res += 1;
            }
        }

        res += balance;

        return res;
    }
};