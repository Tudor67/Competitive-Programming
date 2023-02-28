class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int N = prices.size();

        int res = 0;
        int prefMin = prices[0];
        for(int price: prices){
            prefMin = min(prefMin, price);
            res = max(res, price - prefMin);
        }

        return res;
    }
};