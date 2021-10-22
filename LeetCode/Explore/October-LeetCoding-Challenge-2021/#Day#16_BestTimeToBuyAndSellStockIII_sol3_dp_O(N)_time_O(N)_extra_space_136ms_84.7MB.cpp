class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int N = prices.size();
        
        if(N <= 1){
            return 0;
        }
        
        // dp1[i]: max profit on the ith day if you complete at most one transaction
        vector<int> dp1(N, 0);
        dp1[0] = -prices[0];
        
        int minPrefPrice = prices[0];
        for(int i = 1; i < N; ++i){
            dp1[i] = max(dp1[i - 1], prices[i] - minPrefPrice);
            minPrefPrice = min(minPrefPrice, prices[i]);
        }
        
        // dp1Buy[i]: max profit on the ith day if you complete at most one transaction
        //            followed by a `buy` operation
        vector<int> dp1Buy(N, 0);
        dp1Buy[0] = -prices[0];
        for(int i = 1; i < N; ++i){
            dp1Buy[i] = max(dp1Buy[i - 1], max(0, dp1[i - 1]) - prices[i]);
        }
        
        // dp2[i]: max profit on the ith day if you complete at most two transactions
        vector<int> dp2(N, 0);
        for(int i = 1; i < N; ++i){
            dp2[i] = max(dp2[i - 1], dp1Buy[i - 1] + prices[i]);
        }
        
        return dp2[N - 1];
    }
};