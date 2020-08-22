class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1){
            return 0;
        }
        
        const int N = prices.size();
        vector<vector<int>> max_profit(N, vector<int>(3));
        for(int i = 1; i < N; ++i){
            max_profit[i][1] = max_profit[i - 1][1];
            for(int j = 0; j < i; ++j){
                max_profit[i][1] = max(prices[i] - prices[j], max_profit[i][1]);
            }
            for(int j = 1; j < i; ++j){
                max_profit[i][2] = max(max_profit[j - 1][1] + prices[i] - prices[j], max_profit[i][2]);
            }
        }
        
        int answer = 0;
        for(int i = 0; i < N; ++i){
            answer = max({max_profit[i][1], max_profit[i][2], answer});
        }
        
        return answer;
    }
};