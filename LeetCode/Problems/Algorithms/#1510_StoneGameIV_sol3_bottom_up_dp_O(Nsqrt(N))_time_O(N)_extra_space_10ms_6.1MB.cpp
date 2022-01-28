class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> canWin(n + 1, false);
        for(int i = 0; i <= n; ++i){
            if(!canWin[i]){
                for(int j = 1; i + j * j <= n; ++j){
                    canWin[i + j * j] = true;
                }
            }
        }
        return canWin[n];
    }
};