class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MODULO = 1'000'000'007;

        int goodStrings = 0;

        // dp[len]: number of good strings of length len
        vector<int> dp(high + 1);
        dp[0] = 1;
        for(int len = 1; len <= high; ++len){
            if(len >= zero){
                dp[len] = (dp[len] + dp[len - zero]) % MODULO;
            }
            if(len >= one){
                dp[len] = (dp[len] + dp[len - one]) % MODULO;
            }
            if(len >= low){
                goodStrings = (goodStrings + dp[len]) % MODULO;
            }
        }

        return goodStrings;
    }
};