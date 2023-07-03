class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        const int N = prices.size();

        // dpBuy[i]: max profit for prices[0 .. i] when the last operation is `buy`
        // dpSell[i]: max profit for prices[0 .. i] when the last operation is `sell`
        vector<int> dpBuy(N);
        vector<int> dpSell(N);

        dpBuy[0] = -prices[0];
        dpSell[0] = 0;
        for(int i = 1; i < N; ++i){
            dpBuy[i] = max(dpBuy[i - 1], dpSell[i - 1] - prices[i]);
            dpSell[i] = max(dpSell[i - 1], dpBuy[i - 1] + prices[i] - fee);
        }

        return dpSell[N - 1];
    }
};