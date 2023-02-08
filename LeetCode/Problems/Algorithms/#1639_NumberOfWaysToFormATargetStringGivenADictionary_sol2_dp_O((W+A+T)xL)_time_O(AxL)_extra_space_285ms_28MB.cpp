class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const int TARGET_LEN = target.length();
        const int WORD_LEN = words[0].length();
        const int A = 26;
        const int MODULO = 1e9 + 7;

        vector<vector<int>> count(A, vector<int>(WORD_LEN));
        for(const string& WORD: words){
            for(int j = 0; j < WORD_LEN; ++j){
                count[WORD[j] - 'a'][j] += 1;
            }
        }

        // At ith iteration:
        //    dp[i % 2][j]: number of ways to form target[0 .. i]
        //                  when we use chars from words[..][0 .. j]
        vector<vector<long long>> dp(2, vector<long long>(WORD_LEN));
        for(int j = 0; j < WORD_LEN; ++j){
            if(j == 0){
                dp[0][j] = count[target[0] - 'a'][j];
            }else{
                dp[0][j] = (dp[0][j - 1] + count[target[0] - 'a'][j]) % MODULO;
            }
        }

        for(int i = 1; i < TARGET_LEN; ++i){
            dp[i % 2][0] = 0;
            for(int j = 1; j < WORD_LEN; ++j){
                dp[i % 2][j] = (dp[i % 2][j - 1] + dp[(i - 1) % 2][j - 1] * count[target[i] - 'a'][j]) % MODULO;
            }
        }

        return dp[(TARGET_LEN - 1) % 2][WORD_LEN - 1];
    }
};