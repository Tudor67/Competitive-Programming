class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> minCoins(amount + 1, INT_MAX);
        minCoins[0] = 0;
        for(int coin: coins){
            for(int sum = coin; sum <= amount; ++sum){
                if(minCoins[sum - coin] != INT_MAX){
                    minCoins[sum] = min(1 + minCoins[sum - coin], minCoins[sum]);
                }
            }
        }
        if(minCoins[amount] == INT_MAX){
            minCoins[amount] = -1;
        }
        return minCoins[amount];
    }
};