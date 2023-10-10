class Solution {
public:
    int numOfArrays(int N, int M, int K) {
        if(K == 0){
            return 0;
        }

        const int MODULO = 1e9 + 7;

        // At Kth iteration:
        //    dp[K % 2][prefMax][i]: number of ways to build the array arr[0 .. i]
        //                           such that the search cost is equal to K
        //                           and the max element of arr[0 .. i] is less than or equal to prefMax
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(M + 1, vector<int>(N)));
        for(int prefMax = 1; prefMax <= M; ++prefMax){
            dp[1][prefMax][0] = 1;
        }

        for(int searchCost = 1; searchCost <= K; ++searchCost){
            for(int prefMax = 1; prefMax <= M; ++prefMax){
                for(int i = 0; i + 1 < N; ++i){
                    dp[searchCost % 2][prefMax][i + 1] += (dp[searchCost % 2][prefMax][i] * (long long)prefMax) % MODULO;
                    dp[searchCost % 2][prefMax][i + 1] %= MODULO;
                }
            }
            for(int prefMax = 1; prefMax + 1 <= M; ++prefMax){
                for(int i = 0; i < N; ++i){
                    dp[searchCost % 2][prefMax + 1][i] += dp[searchCost % 2][prefMax][i];
                    dp[searchCost % 2][prefMax + 1][i] %= MODULO;
                }
            }
            for(int prefMax = 0; prefMax <= M; ++prefMax){
                for(int i = 0; i < N; ++i){
                    dp[(searchCost + 1) % 2][prefMax][i] = 0;
                }
            }
            for(int prefMax = 1; prefMax + 1 <= M; ++prefMax){
                for(int i = 0; i + 1 < N; ++i){
                    dp[(searchCost + 1) % 2][prefMax + 1][i + 1] += dp[searchCost % 2][prefMax][i];
                    dp[(searchCost + 1) % 2][prefMax + 1][i + 1] %= MODULO;
                }
            }
        }

        return dp[K % 2][M][N - 1];
    }
};