class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int N = prices.size();

        // At ith iteration:
        //    dpBuy[i % 3]: max profit in range [0 .. i] when the last operation is buy
        //    dpSell[i % 3]: max profit in range [0 .. i] when the last operation is sell
        vector<int> dpBuy(3);
        vector<int> dpSell(3);

        dpBuy[0] = -prices[0];
        for(int i = 1; i < N; ++i){
            dpBuy[i % 3] = max(dpBuy[(i - 1) % 3], dpSell[(i - 2 + 3) % 3] - prices[i]);
            dpSell[i % 3] = max(dpSell[(i - 1) % 3], dpBuy[(i - 1) % 3] + prices[i]);
        }

        return dpSell[(N - 1) % 3];
    }
};