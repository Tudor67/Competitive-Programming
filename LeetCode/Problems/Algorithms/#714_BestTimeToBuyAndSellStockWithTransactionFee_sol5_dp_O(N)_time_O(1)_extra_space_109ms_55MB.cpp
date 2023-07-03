class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        const int N = prices.size();

        // At ith iteration:
        //    dpBuy: max profit for prices[0 .. i] when the last operation is `buy`
        //    dpSell: max profit for prices[0 .. i] when the last operation is `sell`
        int dpBuy = -prices[0];
        int dpSell = 0;
        for(int i = 1; i < N; ++i){
            int newDPBuy = max(dpBuy, dpSell - prices[i]);
            int newDPSell = max(dpSell, dpBuy + prices[i] - fee);
            dpBuy = newDPBuy;
            dpSell = newDPSell;
        }

        return dpSell;
    }
};