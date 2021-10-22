class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int N = prices.size();
        const int K = 2;
        
        if(N <= 1){
            return 0;
        }
        
        // maxProfit[j][i]: max profit on the ith day if you complete at most j transactions
        // maxProfitBuy[j][i]: max profit on the ith day if you complete at most j transactions
        //                     followed by a `buy` operation
        vector<vector<int>> maxProfit(2, vector<int>(N));
        vector<vector<int>> maxProfitBuy(2, vector<int>(N));
        
        int minPrefixPrice = prices[0];
        for(int i = 0; i < N; ++i){
            minPrefixPrice = min(minPrefixPrice, prices[i]);
            maxProfitBuy[0][i] = -minPrefixPrice;
        }
        
        for(int j = 1; j <= K; ++j){
            maxProfitBuy[j % 2][0] = -prices[0];
            for(int i = 1; i < N; ++i){
                maxProfit[j % 2][i] = max(maxProfit[j % 2][i - 1], maxProfitBuy[(j - 1) % 2][i - 1] + prices[i]);
                maxProfitBuy[j % 2][i] = max(maxProfitBuy[j % 2][i - 1], maxProfit[j % 2][i - 1] - prices[i]);
            }
        }
        
        return maxProfit[K % 2][N - 1];
    }
};