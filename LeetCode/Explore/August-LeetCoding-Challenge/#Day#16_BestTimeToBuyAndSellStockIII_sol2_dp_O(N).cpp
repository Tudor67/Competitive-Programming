class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1){
            return 0;
        }
        
        const int N = prices.size();
        vector<vector<int>> max_profit(N, vector<int>(3));
        
        vector<int> min_price(N);
        min_price[0] = prices[0];
        vector<int> max_diff(N);
        max_diff[0] = -prices[0];
        
        for(int i = 1; i < N; ++i){
            max_profit[i][1] = max(prices[i] - min_price[i - 1], max_profit[i - 1][1]);
            max_profit[i][2] = max_diff[i - 1] + prices[i];
            
            min_price[i] = min(min_price[i - 1], prices[i]);
            max_diff[i] = max(max_profit[i - 1][1] - prices[i], max_diff[i - 1]);
        }
        
        int answer = 0;
        for(int i = 0; i < N; ++i){
            answer = max({max_profit[i][1], max_profit[i][2], answer});
        }
        
        return answer;
    }
};