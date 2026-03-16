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

        for(int zeros = 1; zeros <= min(ZEROS, LIMIT); ++zeros){
            dp[0][zeros][0] = 1;
        }

        for(int ones = 1; ones <= min(ONES, LIMIT); ++ones){
            dp[1][0][ones] = 1;
        }

        for(int zeros = 1; zeros <= ZEROS; ++zeros){
            for(int ones = 1; ones <= ONES; ++ones){
                for(int c0 = 1; c0 <= min(zeros, LIMIT); ++c0){
                    add(dp[0][zeros][ones], dp[1][zeros - c0][ones], MODULO);
                }
                for(int c1 = 1; c1 <= min(ones, LIMIT); ++c1){
                    add(dp[1][zeros][ones], dp[0][zeros][ones - c1], MODULO);
                }
            }
        }

        return (dp[0][ZEROS][ONES] + dp[1][ZEROS][ONES]) % MODULO;
    }
};