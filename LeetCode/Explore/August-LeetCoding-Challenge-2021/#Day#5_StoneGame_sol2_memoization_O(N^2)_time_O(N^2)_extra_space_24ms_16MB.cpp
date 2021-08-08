class Solution {
private:
    int computeMaxStones(int l, int r, vector<int>& piles, vector<vector<int>>& memo){
        if(l == r){
            memo[l][r] = piles[r];
        }else if(memo[l][r] == -1){
            int maxLeftStones = piles[l] - computeMaxStones(l + 1, r, piles, memo);
            int maxRightStones = piles[r] - computeMaxStones(l, r - 1, piles, memo);
            memo[l][r] = max(maxLeftStones, maxRightStones);
        }
        return memo[l][r];
    }
    
public:
    bool stoneGame(vector<int>& piles) {
        const int N = piles.size();
        const int TOTAL_STONES = accumulate(piles.begin(), piles.end(), 0);
        vector<vector<int>> memo(N, vector<int>(N, -1));
        return (TOTAL_STONES - computeMaxStones(0, N - 1, piles, memo) >= 1);
    }
};