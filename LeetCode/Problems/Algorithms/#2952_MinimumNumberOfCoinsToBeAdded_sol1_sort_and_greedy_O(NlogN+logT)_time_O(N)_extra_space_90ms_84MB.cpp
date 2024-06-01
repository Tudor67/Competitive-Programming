class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        const int N = coins.size();

        vector<int> sortedCoins = coins;
        sort(sortedCoins.begin(), sortedCoins.end());

        int addedCoins = 0;
        int maxValidSum = 0;
        int i = 0;
        while(maxValidSum < target){
            if(i < N && sortedCoins[i] <= maxValidSum + 1){
                maxValidSum += sortedCoins[i];
                i += 1;
            }else{
                maxValidSum += (maxValidSum + 1);
                addedCoins += 1;
            }
        }

        return addedCoins;
    }
};