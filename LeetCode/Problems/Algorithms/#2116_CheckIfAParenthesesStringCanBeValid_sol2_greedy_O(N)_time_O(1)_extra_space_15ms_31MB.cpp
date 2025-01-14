class Solution {
private:
    bool isValid(string& s, string& locked, int startIndex, int endIndex, int direction) {
        const int N = s.length();

        if(N % 2 == 1){
            return false;
        }

        int balance = 0;
        for(int i = startIndex; i != endIndex; i += direction){
            if((locked[i] == '0') ||
               (s[i] == '(' && direction == 1) ||
               (s[i] == ')' && direction == -1)){
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

public:
    bool canBeValid(string s, string locked) {
        const int N = s.length();
        return isValid(s, locked, 0, N, 1) &&
               isValid(s, locked, N - 1, -1, -1);
    }
};