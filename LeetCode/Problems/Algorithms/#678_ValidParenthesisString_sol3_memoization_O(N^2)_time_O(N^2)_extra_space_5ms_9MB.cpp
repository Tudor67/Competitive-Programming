class Solution {
private:
    bool check(int balance, int i, string& s, vector<vector<short int>>& memo){
        const int N = s.length();

        if(balance < 0){
            return false;
        }

        if(i == N){
            return (balance == 0);
        }

        if(memo[balance][i] == -1){
            bool isValid = false;
            if(s[i] == '('){
                isValid = check(balance + 1, i + 1, s, memo);
            }else if(s[i] == ')'){
                isValid = check(balance - 1, i + 1, s, memo);
            }else{
                isValid = check(balance, i + 1, s, memo) ||
                          check(balance + 1, i + 1, s, memo) ||
                          check(balance - 1, i + 1, s, memo);
            }
            memo[balance][i] = isValid;
        }

        return (bool)memo[balance][i];
    }

public:
    bool checkValidString(string s) {
        const int N = s.length();
        vector<vector<short int>> memo(N + 1, vector<short int>(N + 1, -1));
        return check(0, 0, s, memo);
    }
};