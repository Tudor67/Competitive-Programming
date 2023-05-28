class Solution {
private:
    const int INF = 1e9;

    int computeMaxDiff(int index, int m, vector<int>& piles, vector<vector<int>>& memo){
        const int N = piles.size();

        if(index >= N){
            return 0;
        }

        if(memo[index][m] != -INF){
            return memo[index][m];
        }

        int maxDiff = -INF;
        int prefSum = 0;
        for(int i = index; i <= min(index + 2 * m - 1, N - 1); ++i){
            prefSum += piles[i];
            int diff = prefSum - computeMaxDiff(i + 1, max(min(i - index + 1, N), m), piles, memo);
            maxDiff = max(maxDiff, diff);
        }

        memo[index][m] = maxDiff;
        return memo[index][m];
    }

public:
    int stoneGameII(vector<int>& piles) {
        const int N = piles.size();
        const int TOTAL_SUM = accumulate(piles.begin(), piles.end(), 0);

        vector<vector<int>> memo(N + 1, vector<int>(N + 1, -INF));
        int maxDiff = computeMaxDiff(0, 1, piles, memo);

        return (TOTAL_SUM - maxDiff) / 2 + maxDiff;
    }
};