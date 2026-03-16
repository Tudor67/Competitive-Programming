class Solution {
private:
    void add(int& a, int b, const int MODULO){
        a = (a + b) % MODULO;
    }

public:
    int numberOfStableArrays(int ZEROS, int ONES, int LIMIT) {
        const int MODULO = 1'000'000'007;
        // dp[`last`][`zeros`][`ones`]: number of stable arrays with exactly `zeros` 0s and `ones` 1s
        //                              with the last element equal to `last`
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(ZEROS + 1, vector<int>(ONES + 1)));
        dp[0][0][0] = 1;
        dp[1][0][0] = 1;

        for(int zeros = 0; zeros <= ZEROS; ++zeros){
            for(int ones = 0; ones <= ONES; ++ones){
                for(int cons = 1; cons <= LIMIT; ++cons){
                    if(ones + cons <= ONES){
                        add(dp[1][zeros][ones + cons], dp[0][zeros][ones], MODULO);
                    }
                    if(zeros + cons <= ZEROS){
                        add(dp[0][zeros + cons][ones], dp[1][zeros][ones], MODULO);
                    }
                }
            }
        }

        return (dp[0][ZEROS][ONES] + dp[1][ZEROS][ONES]) % MODULO;
    }
};