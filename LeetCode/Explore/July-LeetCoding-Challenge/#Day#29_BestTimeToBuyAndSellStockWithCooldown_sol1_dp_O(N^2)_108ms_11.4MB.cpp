class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int answer = 0;
        
        if(prices.size() >= 2){
            const int N = prices.size();
            vector<int> max_profit(N);
            // max_profit[i] - max profit on day i (if we sell or cooldown on day i);
            //               - only non-negative values (>= 0);
            // remember: - we cannot sell anything on day i if we did not buy in at least one day from the range [0, i - 1];
            //           - we cannot buy on the current day if we sold in the previous day;

            for(int i = 1; i < N; ++i){
                int max_profit_for_sell = 0;
                for(int j = i - 1; j >= 0; --j){
                    max_profit_for_sell = max(prices[i] - prices[j] + (j >= 2 ? max_profit[j - 2] : 0),
                                              max_profit_for_sell);
                }
                int max_profit_for_cooldown = max_profit[i - 1];
                max_profit[i] = max(max_profit_for_sell, max_profit_for_cooldown);
            }
            
            answer = max_profit[N - 1];
        }
        
        return answer;
    }
};