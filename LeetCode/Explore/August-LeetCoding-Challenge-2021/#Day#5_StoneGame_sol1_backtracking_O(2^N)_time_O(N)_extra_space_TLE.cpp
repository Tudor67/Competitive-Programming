class Solution {
private:
    int computeMaxStones(int l, int r, vector<int>& piles){
        if(l == r){
            return piles[r];
        }
        int maxLeftStones = piles[l] - computeMaxStones(l + 1, r, piles);
        int maxRightStones = piles[r] - computeMaxStones(l, r - 1, piles);
        return max(maxLeftStones, maxRightStones);
    }
    
public:
    bool stoneGame(vector<int>& piles) {
        const int N = piles.size();
        const int TOTAL_STONES = accumulate(piles.begin(), piles.end(), 0);
        return (TOTAL_STONES - computeMaxStones(0, N - 1, piles) >= 1);
    }
};