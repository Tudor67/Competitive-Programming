class Solution {
private:
    int computeMaxCoins(vector<vector<int>>& piles, int k, int i, vector<vector<int>>& memo){
        const int N = piles.size();

        if(i == N || k == 0){
            return 0;
        }

        if(memo[k][i] != -1){
            return memo[k][i];
        }

        int maxCoins = computeMaxCoins(piles, k, i + 1, memo);
        int pilePrefixCoins = 0;
        for(int j = 0; j < min(k, (int)piles[i].size()); ++j){
            pilePrefixCoins += piles[i][j];
            maxCoins = max(maxCoins, pilePrefixCoins + computeMaxCoins(piles, k - 1 - j, i + 1, memo));
        }

        memo[k][i] = maxCoins;
        return maxCoins;
    }

public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        const int N = piles.size();
        vector<vector<int>> memo(k + 1, vector<int>(N, -1));
        return computeMaxCoins(piles, k, 0, memo);
    }
};