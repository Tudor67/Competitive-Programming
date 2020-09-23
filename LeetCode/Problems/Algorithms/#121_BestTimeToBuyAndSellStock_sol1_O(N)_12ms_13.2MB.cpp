class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        
        if(!prices.empty()){
            int minPrice = prices[0];
            for(int i = 1; i < prices.size(); ++i){
                maxProfit = max(prices[i] - minPrice, maxProfit);
                minPrice = min(prices[i], minPrice);
            }
        }
        
        return maxProfit;
    }
};