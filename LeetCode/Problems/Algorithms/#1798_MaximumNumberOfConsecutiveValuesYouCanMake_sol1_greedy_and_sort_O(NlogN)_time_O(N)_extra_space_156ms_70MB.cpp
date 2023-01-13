class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        const int N = coins.size();

        vector<int> sortedCoins = coins;
        sort(sortedCoins.begin(), sortedCoins.end());

        int maxVal = 0;
        for(int i = 0; i < N; ++i){
            if(maxVal + 1 >= sortedCoins[i]){
                maxVal += sortedCoins[i];
            }else{
                break;
            }
        }

        return maxVal + 1;
    }
};