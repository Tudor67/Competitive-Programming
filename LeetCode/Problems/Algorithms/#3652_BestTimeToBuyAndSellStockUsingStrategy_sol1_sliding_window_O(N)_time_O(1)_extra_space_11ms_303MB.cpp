class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        const int N = prices.size();

        long long totalSum = 0;
        for(int i = 0; i < N; ++i){
            totalSum += strategy[i] * prices[i];
        }

        long long res = totalSum;
        long long wOldSum = 0;
        long long wNewSum = 0;

        for(int i = 0; i < N; ++i){
            wOldSum += strategy[i] * prices[i];
            wNewSum += prices[i];
            
            if(i >= k){
                wOldSum -= strategy[i - k] * prices[i - k];
            }
            if(i >= k / 2){
                wNewSum -= prices[i - k / 2];
            }

            if(i >= k - 1){
                res = max(res, totalSum - wOldSum + wNewSum);
            }
        }

        return res;
    }
};