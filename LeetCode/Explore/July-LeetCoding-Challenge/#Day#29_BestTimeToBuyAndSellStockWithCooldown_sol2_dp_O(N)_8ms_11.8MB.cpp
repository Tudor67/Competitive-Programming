class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int answer = 0;
        
        if(prices.size() >= 2){
            const int N = prices.size();
            const int BUY = 0;
            const int SELL_OR_COOLDOWN = 1;
            
            vector<vector<int>> max_profit(N, vector<int>(2));
            max_profit[0][BUY] = -prices[0];
            max_profit[0][SELL_OR_COOLDOWN] = 0;
            // max_profit[i][BUY] - max profit on day i (if the last transaction in the range [0, i] was 'BUY');
            //                    - we can have negative values;
            // max_profit[i][SELL_OR_COOLDOWN] - max profit on day i (if the transaction on day i was 'SELL' or 'COOLDOWN');
            //                                 - only non-negative values (>= 0);
            // remember: - we cannot sell anything on day i if we did not buy in at least one day from the range [0, i - 1];
            //           - we cannot buy on the current day if we sold in the previous day;

            for(int i = 1; i < N; ++i){
                max_profit[i][BUY] = max(-prices[i] + (i >= 2 ? max_profit[i - 2][SELL_OR_COOLDOWN] : 0),
                                         max_profit[i - 1][BUY]);
                int max_profit_for_sell = prices[i] + max_profit[i - 1][BUY];
                int max_profit_for_cooldown = max_profit[i - 1][SELL_OR_COOLDOWN];
                max_profit[i][SELL_OR_COOLDOWN] = max(max_profit_for_sell, max_profit_for_cooldown);
            }
            
            answer = max_profit[N - 1][SELL_OR_COOLDOWN];
        }
        
        return answer;
    }
};