class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> canWin(n + 1, false);
        canWin[0] = false;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j * j <= i; ++j){
                if(!canWin[i - j * j]){
                    canWin[i] = true;
                    break;
                }
            }
        }
        return canWin[n];
    }
};