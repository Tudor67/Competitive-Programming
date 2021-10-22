class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int N = prices.size();
        const int K = 2;
        
        if(N <= 1){
            return 0;
        }
        
        // maxProfit[i][j]: max profit on the ith day if you complete at most j transactions
        // maxProfitBuy[i][j]: max profit on the ith day if you complete at most j transactions
        //                     followed by a `buy` operation
        vector<vector<int>> maxProfit(N, vector<int>(K + 1));
        vector<vector<int>> maxProfitBuy(N, vector<int>(K + 1));
        
        int minPrefixPrice = prices[0];
        for(int i = 0; i < N; ++i){
            minPrefixPrice = min(minPrefixPrice, prices[i]);
            maxProfitBuy[i][0] = -minPrefixPrice;
        }
        
        for(int j = 1; j <= K; ++j){
            maxProfitBuy[0][j] = -prices[0];
            for(int i = 1; i < N; ++i){
                maxProfit[i][j] = max(maxProfit[i - 1][j], maxProfitBuy[i - 1][j - 1] + prices[i]);
                maxProfitBuy[i][j] = max(maxProfitBuy[i - 1][j], maxProfit[i - 1][j] - prices[i]);
            }
        }
        
        return maxProfit[N - 1][K];
    }
};