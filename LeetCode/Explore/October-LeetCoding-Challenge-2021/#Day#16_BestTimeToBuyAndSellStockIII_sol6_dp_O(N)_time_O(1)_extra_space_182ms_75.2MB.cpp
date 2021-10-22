class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int firstBuyProfit = -prices[0];
        int firstSellProfit = 0;
        int secondBuyProfit = -prices[0];
        int secondSellProfit = 0;
        for(int price: prices){
            firstBuyProfit = max(firstBuyProfit, -price);
            firstSellProfit = max(firstSellProfit, firstBuyProfit + price);
            secondBuyProfit = max(secondBuyProfit, firstSellProfit - price);
            secondSellProfit = max(secondSellProfit, secondBuyProfit + price);
        }
        return secondSellProfit;
    }
};