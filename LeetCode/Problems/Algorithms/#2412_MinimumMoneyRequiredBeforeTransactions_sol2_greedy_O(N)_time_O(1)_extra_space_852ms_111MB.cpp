class Solution { 
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        // badTransactions:  cost >  cashback
        // goodTransactions: cost <= cashback
        long long money = 0;
        int maxCashbackOfBadTransactions = 0;
        int maxCostOfGoodTransactions = 0;
        for(const vector<int>& T: transactions){
            int cost = T[0];
            int cashback = T[1];
            if(cost > cashback){
                money -= cost;
                money += cashback;
                maxCashbackOfBadTransactions = max(maxCashbackOfBadTransactions, cashback);
            }else{
                maxCostOfGoodTransactions = max(maxCostOfGoodTransactions, cost);
            }
        }
        
        long long res = max(-(money - maxCashbackOfBadTransactions),
                            -(money - maxCostOfGoodTransactions));
        
        return res;
    }
};