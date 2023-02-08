class Solution {
public:
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        const int Q = queries.size();
        const int MODULO = 1e9 + 7;

        int maxN = 0;
        int maxK = 0;
        for(int i = 0; i < Q; ++i){
            maxN = max(maxN, queries[i][0]);
            maxK = max(maxK, queries[i][1]);
        }

        // dp[n][k]: number of different ways we can write k as product of n positive numbers
        vector<vector<long long>> dp(maxN + 1, vector<long long>(maxK + 1));
        for(int i = 1; i <= maxN; ++i){
            dp[i][1] = 1;
        }
        for(int k = 1; k <= maxK; ++k){
            dp[1][k] = 1;
        }

        for(int i = 1; i <= maxN - 1; ++i){
            for(int k = 1; k <= maxK; ++k){
                for(int f = 1; k * f <= maxK; ++f){
                    if(k * f != 1){
                        dp[i + 1][k * f] += dp[i][k];
                        dp[i + 1][k * f] %= MODULO;
                    }
                }
            }
        }

        vector<int> answer(Q);
        for(int i = 0; i < Q; ++i){
            const int N = queries[i][0];
            const int K = queries[i][1];
            answer[i] = dp[N][K];
        }

        return answer;
    }
};