class Solution {
private:
    const int INF = INT_MAX;

    int f(int l, int r, vector<int>& piles, vector<vector<int>>& memo){
        if(l == r){
            return piles[r];
        }
        if(memo[l][r] == INF){
            memo[l][r] = max(piles[l] - f(l + 1, r, piles, memo),
                             piles[r] - f(l, r - 1, piles, memo));
        }
        return memo[l][r];
    }

public:
    bool stoneGame(vector<int>& piles) {
        const int N = piles.size();
        vector<vector<int>> memo(N, vector<int>(N, INF));
        return (f(0, N - 1, piles, memo) > 0);
    }
};