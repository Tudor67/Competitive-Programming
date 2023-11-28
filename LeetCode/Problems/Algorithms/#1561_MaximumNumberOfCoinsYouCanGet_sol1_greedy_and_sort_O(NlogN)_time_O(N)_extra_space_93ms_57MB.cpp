class Solution {
public:
    int maxCoins(vector<int>& piles) {
        const int N = piles.size() / 3;

        vector<int> sortedPiles = piles;
        sort(sortedPiles.begin(), sortedPiles.end());

        int res = 0;
        for(int i = 3 * N - 2; i >= N; i -= 2){
            res += sortedPiles[i];
        }

        return res;
    }
};