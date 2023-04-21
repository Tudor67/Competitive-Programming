class Solution {
private:
    long long getVal(vector<vector<long long>>& dp, int i, int j){
        if(0 <= i && i < (int)dp.size() && 0 <= j && j < (int)dp[i].size()){
            return dp[i][j];
        }
        if(i < 0){
            return 1;
        }
        return 0;
    }

public:
    int numWays(vector<string>& words, string target) {
        const int W = words.size();
        const int L = words[0].length();
        const int T = target.length();
        const int A = 26;
        const int FIRST_CHAR = 'a';
        const int MODULO = 1e9 + 7;

        // count[c - FIRST_CHAR][j]: count of char c in words[..][j]
        vector<vector<long long>> count(A, vector<long long>(L));
        for(int i = 0; i < W; ++i){
            for(int j = 0; j < L; ++j){
                count[words[i][j] - FIRST_CHAR][j] += 1;
            }
        }

        // At ith iteration:
        //    dp[i % 2][j]: number of ways to form target[0 .. i] from words[..][0 .. j]
        vector<vector<long long>> dp(2, vector<long long>(L));
        for(int i = 0; i < T; ++i){
            for(int j = 0; j < L; ++j){
                dp[i % 2][j] = (getVal(dp, i % 2, j - 1) + 
                                getVal(dp, (i - 1) % 2, j - 1) * count[target[i] - FIRST_CHAR][j]) % MODULO;
            }
        }
        
        return dp[(T - 1) % 2][L - 1];
    }
};