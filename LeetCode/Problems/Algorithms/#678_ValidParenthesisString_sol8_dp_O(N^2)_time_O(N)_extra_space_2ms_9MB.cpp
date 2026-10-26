class Solution {
private:
    bool getVal(vector<vector<bool>>& dp, int i, int balance){
        if(0 <= i && i < (int)dp.size() && 0 <= balance && balance < (int)dp[i].size()){
            return dp[i][balance];
        }
        return false;
    }

public:
    bool checkValidString(string s) {
        const int N = s.length();

        // At ith iteration:
        // dp[i % 2][b] = true, if s[0 .. i] can reach balance b
        //                false, otherwise
        vector<vector<bool>> dp(2, vector<bool>(N + 1));

        if(s[0] == '*'){
            dp[0][0] = true;
            dp[0][1] = true;
        }else if(s[0] == '('){
            dp[0][1] = true;
        }

        for(int i = 1; i < N; ++i){
            for(int balance = 0; balance <= N; ++balance){
                if(s[i] == '*'){
                    dp[i % 2][balance] = getVal(dp, (i - 1) % 2, balance) ||
                                         getVal(dp, (i - 1) % 2, balance - 1) ||
                                         getVal(dp, (i - 1) % 2, balance + 1);
                }else if(s[i] == '('){
                    dp[i % 2][balance] = getVal(dp, (i - 1) % 2, balance - 1);
                }else{
                    dp[i % 2][balance] = getVal(dp, (i - 1) % 2, balance + 1);
                }
            }
        }

        return dp[(N - 1) % 2][0];
    }
};