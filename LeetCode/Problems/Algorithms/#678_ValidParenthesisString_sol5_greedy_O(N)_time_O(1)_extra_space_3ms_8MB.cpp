class Solution {
public:
    bool checkValidString(string s) {
        const int N = s.length();

        // Step 1: Process parentheses from left to right
        //         check if all ')' have a corresponding pair ('(' or '*') on the left
        int balance = 0;
        for(int i = 0; i < N; ++i){
            if(s[i] == '(' || s[i] == '*'){
                balance += 1;
            }else{
                balance -= 1;
            }
            if(balance < 0){
                return false;
            }
        }

        // Step 2: Process parentheses from right to left
        //         check if all '(' have a corresponding pair (')' or '*') on the right
        balance = 0;
        for(int i = N - 1; i >= 0; --i){
            if(s[i] == ')' || s[i] == '*'){
                balance += 1;
            }else{
                balance -= 1;
            }
            if(balance < 0){
                return false;
            }
        }

        return true;
    }
};