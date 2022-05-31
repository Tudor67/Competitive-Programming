class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int C = coins.size();
        const int A = amount;
        const int INF = 1e9;
        
        vector<int> minCoins(A + 1, INF);
        minCoins[0] = 0;
        for(int coin: coins){
            for(int sum = coin; sum <= A; ++sum){
                minCoins[sum] = min(minCoins[sum], minCoins[sum - coin] + 1);
            }
        }
        
        int res = minCoins[A];
        if(res == INF){
            res = -1;
        }
        
        return res;
    }
};