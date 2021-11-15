class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int N = prices.size();
        int maxProfit = 0;
        for(int i = 1; i < N; ++i){
            maxProfit += max(0, prices[i] - prices[i - 1]);
        }
        return maxProfit;
    }
};