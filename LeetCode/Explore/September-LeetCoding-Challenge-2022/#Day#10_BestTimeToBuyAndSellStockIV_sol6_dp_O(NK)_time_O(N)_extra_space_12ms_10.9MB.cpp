class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        const int N = prices.size();
        
        if(N == 0 || k == 0){
            return 0;
        }
        
        // At kth iteration:
        //    dpBuy[k % 2][i]: max profit when we complete at most k transactions in range [0 .. i] and the last operation is `BUY`
        //    dpSell[k % 2][i]: max profit when we complete at most k transactions in range [0 .. i] and the last operation is `SELL`
        vector<vector<int>> dpBuy(2, vector<int>(N));
        vector<vector<int>> dpSell(2, vector<int>(N));
        
        dpBuy[0][0] = -prices[0];
        for(int i = 1; i < N; ++i){
            dpBuy[0][i] = max(dpBuy[0][i - 1], -prices[i]);
        }
        
        for(int transactions = 1; transactions <= k; ++transactions){
            dpBuy[transactions % 2][0] = -prices[0];
            for(int i = 1; i < N; ++i){
                dpSell[transactions % 2][i] = max(dpSell[transactions % 2][i - 1], dpBuy[(transactions - 1) % 2][i - 1] + prices[i]);
                dpBuy[transactions % 2][i] = max(dpBuy[transactions % 2][i - 1], dpSell[transactions % 2][i - 1] - prices[i]);
            }
        }
        
        return dpSell[k % 2][N - 1];
    }
};