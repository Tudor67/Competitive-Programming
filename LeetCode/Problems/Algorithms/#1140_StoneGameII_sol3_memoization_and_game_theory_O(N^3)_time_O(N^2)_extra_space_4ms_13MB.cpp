class Solution {
private:
    const int INF = 1e9;

    int f(int startIndex, const int M, vector<int>& suffSum, vector<vector<int>>& memo){
        const int N = suffSum.size();

        if(startIndex == N){
            return 0;
        }

        if(memo[startIndex][M] != INF){
            return memo[startIndex][M];
        }

        int maxStones = -INF;
        for(int i = startIndex; i < min(startIndex + 2 * M, N); ++i){
            maxStones = max(maxStones, suffSum[startIndex] -
                                       f(i + 1, min(max(M, i - startIndex + 1), N), suffSum, memo));
        }

        memo[startIndex][M] = maxStones;
        return maxStones;
    }

public:
    int stoneGameII(vector<int>& piles) {
        const int N = piles.size();

        vector<int> suffSum(N);
        suffSum[N - 1] = piles[N - 1];
        for(int i = N - 2; i >= 0; --i){
            suffSum[i] = piles[i] + suffSum[i + 1];
        }

        vector<vector<int>> memo(N, vector<int>(N + 1, INF));
        return f(0, 1, suffSum, memo);
    }
};