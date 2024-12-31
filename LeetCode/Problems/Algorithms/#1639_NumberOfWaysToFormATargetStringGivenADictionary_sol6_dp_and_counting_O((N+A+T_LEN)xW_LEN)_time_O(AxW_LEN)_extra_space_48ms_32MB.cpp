class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const int N = words.size();
        const int W_LEN = words[0].length();
        const int T_LEN = target.length();
        const int A = 26;
        const int MODULO = 1'000'000'007;

        vector<vector<int>> freq(A, vector<int>(W_LEN));
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < W_LEN; ++j){
                freq[words[i][j] - 'a'][j] += 1;
            }
        }

        // At ith iteration:
        //    dp[i % 2][j]: number of ways to form target[0 .. i] from the first (j + 1) chars of words
        vector<vector<int>> dp(2, vector<int>(W_LEN));
        dp[0][0] = freq[target[0] - 'a'][0];
        for(int j = 1; j < W_LEN; ++j){
            dp[0][j] = (dp[0][j - 1] + freq[target[0] - 'a'][j]) % MODULO;
        }

        for(int i = 1; i < T_LEN; ++i){
            dp[i % 2][0] = 0;
            for(int j = 1; j < W_LEN; ++j){
                dp[i % 2][j] = (dp[i % 2][j - 1] +
                                dp[(i - 1) % 2][j - 1] * 1LL * freq[target[i] - 'a'][j]) % MODULO;
            }
        }

        return dp[(T_LEN - 1) % 2][W_LEN - 1];
    }
};