class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        const int N = prices.size();
        
        if(N == 0 || k == 0){
            return 0;
        }
        
        // dpBuy[k][i]: max profit when we complete at most k transactions in range [0 .. i] and the last operation is `BUY`
        // dpSell[k][i]: max profit when we complete at most k transactions in range [0 .. i] and the last operation is `SELL`
        vector<vector<int>> dpBuy(k + 1, vector<int>(N));
        vector<vector<int>> dpSell(k + 1, vector<int>(N));
        
        dpBuy[0][0] = -prices[0];
        for(int i = 1; i < N; ++i){
            dpBuy[0][i] = max(dpBuy[0][i - 1], -prices[i]);
        }
        
        for(int transactions = 1; transactions <= k; ++transactions){
            dpBuy[transactions][0] = -prices[0];
            for(int i = 1; i < N; ++i){
                dpSell[transactions][i] = max(dpSell[transactions][i - 1], dpBuy[transactions - 1][i - 1] + prices[i]);
                dpBuy[transactions][i] = max(dpBuy[transactions][i - 1], dpSell[transactions][i - 1] - prices[i]);
            }
        }
        
        return dpSell[k][N - 1];
    }
};