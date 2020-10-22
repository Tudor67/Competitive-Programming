class Solution {
public:
    int maxProfit(int K, vector<int>& prices) {
        const int N = prices.size();
        
        // Case 1: K == 0 or N <= 1
        if(K == 0 || N <= 1){
            return 0;
        }
        
        // Case 2: 2 * K >= N
        if(2 * K >= N){
            int answer = 0;
            for(int i = 1; i < N; ++i){
                answer += max(0, prices[i] - prices[i - 1]);
            }
            return answer;
        }
        
        // Case 3: 2 * K < N
        // dp[i][j][0] - max profit at the end of ith day,
        //               with max j valid selling transactions, without holding the stock
        // dp[i][j][1] - max profit at the end of ith day, 
        //               with max j valid selling transactions, holding the stock
        // compress the 2nd coordinate, because we need only (j - 1)th and jth values
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(2, vector<int>(2)));
        dp[0][0][1] = -prices[0];
        dp[0][1][1] = -prices[0];
        for(int i = 1; i < N; ++i){
            dp[i][0][1] = max(dp[i - 1][0][1], -prices[i]);
        }
        
        int answer = 0;
        for(int j = 1; j <= K; ++j){
            for(int i = 1; i < N; ++i){
                dp[i][j % 2][0] = max(dp[i - 1][j % 2][0], dp[i - 1][(j - 1) % 2][1] + prices[i]);
                dp[i][j % 2][1] = max(dp[i - 1][j % 2][1], dp[i - 1][j % 2][0] - prices[i]);
            }
            answer = max(dp[N - 1][j % 2][0], answer);
        }
        
        return answer;
    }
};