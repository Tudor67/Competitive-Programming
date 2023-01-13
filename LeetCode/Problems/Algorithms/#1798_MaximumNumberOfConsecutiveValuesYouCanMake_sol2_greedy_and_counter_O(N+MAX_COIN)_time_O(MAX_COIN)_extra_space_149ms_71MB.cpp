class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        const int N = coins.size();
        const int MAX_COIN = *max_element(coins.begin(), coins.end());

        vector<int> count(MAX_COIN + 1);
        for(int coin: coins){
            count[coin] += 1;
        }
        
        int maxVal = 0;
        for(int coin = 1; coin <= MAX_COIN; ++coin){
            while(count[coin] >= 1 && maxVal + 1 >= coin){
                maxVal += coin;
                count[coin] -= 1;
            }
        }

        return maxVal + 1;
    }
};