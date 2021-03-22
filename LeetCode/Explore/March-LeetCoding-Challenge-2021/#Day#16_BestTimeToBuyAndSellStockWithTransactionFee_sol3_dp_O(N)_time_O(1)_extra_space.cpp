class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int maxProfit0 = 0;          // max profit if we do not have a stock
        int maxProfit1 = -prices[0]; // max profit if we have a stock
        for(int i = 1; i < (int)prices.size(); ++i){
            maxProfit0 = max(prices[i] - fee + maxProfit1, maxProfit0);
            maxProfit1 = max(maxProfit0 - prices[i], maxProfit1);
        }
        return maxProfit0;
    }
};