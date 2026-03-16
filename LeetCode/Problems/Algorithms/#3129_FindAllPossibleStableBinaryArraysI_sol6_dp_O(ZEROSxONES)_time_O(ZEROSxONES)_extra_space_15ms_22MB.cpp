class Solution {
public:
    int numberOfStableArrays(int ZEROS, int ONES, int LIMIT) {
        const int MODULO = 1'000'000'007;
        // dp[`last`][`zeros`][`ones`]: number of stable arrays with exactly `zeros` 0s and `ones` 1s
        //                              with the last element equal to `last`
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(ZEROS + 1, vector<int>(ONES + 1)));

        for(int zeros = 1; zeros <= min(ZEROS, LIMIT); ++zeros){
            dp[0][zeros][0] = 1;
        }

        for(int ones = 1; ones <= min(ONES, LIMIT); ++ones){
            dp[1][0][ones] = 1;
        }

        for(int zeros = 1; zeros <= ZEROS; ++zeros){
            for(int ones = 1; ones <= ONES; ++ones){
                dp[0][zeros][ones] = (dp[0][zeros - 1][ones] + dp[1][zeros - 1][ones]) % MODULO;
                if(zeros - LIMIT - 1 >= 0){
                    dp[0][zeros][ones] = (dp[0][zeros][ones] + MODULO - dp[1][zeros - LIMIT - 1][ones]) % MODULO;
                }
                
                dp[1][zeros][ones] = (dp[1][zeros][ones - 1] + dp[0][zeros][ones - 1]) % MODULO;
                if(ones - LIMIT - 1 >= 0){
                    dp[1][zeros][ones] = (dp[1][zeros][ones] + MODULO - dp[0][zeros][ones - LIMIT - 1]) % MODULO;
                }
            }
        }

        return (dp[0][ZEROS][ONES] + dp[1][ZEROS][ONES]) % MODULO;
    }
};