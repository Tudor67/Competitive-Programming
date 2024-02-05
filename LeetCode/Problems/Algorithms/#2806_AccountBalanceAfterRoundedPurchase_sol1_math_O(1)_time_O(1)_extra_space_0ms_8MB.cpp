class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int roundedAmount = (purchaseAmount / 10) * 10;
        if(purchaseAmount % 10 >= 5){
            roundedAmount += 10;
        }
        return 100 - roundedAmount;
    }
};