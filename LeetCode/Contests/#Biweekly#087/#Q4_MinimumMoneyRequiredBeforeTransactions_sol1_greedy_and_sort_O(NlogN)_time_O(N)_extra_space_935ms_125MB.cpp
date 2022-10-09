class Solution {
private:
    static bool incCashbackComp(const pair<int, int>& LHS, const pair<int, int>& RHS){
        int lhsCashback = LHS.second;
        int rhsCashback = RHS.second;
        return (lhsCashback < rhsCashback);
    }
    
    static bool decCostComp(const pair<int, int>& LHS, const pair<int, int>& RHS){
        int lhsCost = LHS.first;
        int rhsCost = RHS.first;
        return (lhsCost > rhsCost);
    }
    
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        vector<pair<int, int>> badTransactions;  // cost >  cashback
        vector<pair<int, int>> goodTransactions; // cost <= cashback
        for(const vector<int>& T: transactions){
            int cost = T[0];
            int cashback = T[1];
            if(cost > cashback){
                badTransactions.emplace_back(cost, cashback);
            }else{
                goodTransactions.emplace_back(cost, cashback);
            }
        }
        
        sort(badTransactions.begin(), badTransactions.end(), incCashbackComp);
        sort(goodTransactions.begin(), goodTransactions.end(), decCostComp);
        
        vector<pair<int, int>> badAndGoodTransactions;
        copy(badTransactions.begin(), badTransactions.end(), back_inserter(badAndGoodTransactions));
        copy(goodTransactions.begin(), goodTransactions.end(), back_inserter(badAndGoodTransactions));
        
        long long res = 0;
        long long money = 0;
        for(const pair<int, int>& T: badAndGoodTransactions){
            int cost = T.first;
            int cashback = T.second;
            money -= cost;
            res = max(res, -money);
            money += cashback;
        }
        
        return res;
    }
};