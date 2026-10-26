class Solution {
public:
    bool checkValidString(string s) {
        const int N = s.length();

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