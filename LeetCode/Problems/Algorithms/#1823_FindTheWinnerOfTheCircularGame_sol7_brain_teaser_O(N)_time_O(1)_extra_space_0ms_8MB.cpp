class Solution {
public:
    int findTheWinner(int n, int k) {
        int winnerIndex = 0;
        for(int i = 2; i <= n; ++i){
            winnerIndex = (winnerIndex + k) % i;
        }
        return 1 + winnerIndex;
    }
};