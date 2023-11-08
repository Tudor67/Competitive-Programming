class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        const int N = prices.size();
        
        vector<int> sortedPrices = prices;
        sort(sortedPrices.begin(), sortedPrices.end());
        
        int diff = money - (sortedPrices[0] + sortedPrices[1]);
        if(diff >= 0){
            return diff;
        }
        
        return money;
    }
};