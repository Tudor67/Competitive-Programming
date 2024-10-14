class Solution {
public:
    int minAddToMakeValid(string s) {
        int minAddOps = 0;

        int balance = 0;
        for(char c: s){
            if(c == '('){
                balance += 1;
            }else if(balance >= 1){
                balance -= 1;
            }else{
                minAddOps += 1;
            }
        }

        return minAddOps + balance;
    }
};