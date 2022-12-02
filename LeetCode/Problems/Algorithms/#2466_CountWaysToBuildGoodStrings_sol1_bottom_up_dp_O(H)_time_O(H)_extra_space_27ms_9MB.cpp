class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MODULO = 1e9 + 7;
        
        // dp[i]: number of 0-1 strings of length i
        vector<int> dp(high + 1);
        dp[0] = 1;
        for(int i = 1; i <= high; ++i){
            if(i >= zero){
                dp[i] = (dp[i] + dp[i - zero]) % MODULO;
            }
            if(i >= one){
                dp[i] = (dp[i] + dp[i - one]) % MODULO;
            }
        }
        
        int res = 0;
        for(int i = low; i <= high; ++i){
            res = (res + dp[i]) % MODULO;
        }
        
        return res;
    }
};