class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        const int MODULO = 1'000'000'007;

        vector<int> cntFor(n + 1, -1);
        for(vector<int>& req: requirements){
            cntFor[req[0] + 1] = req[1];
        }
        
        int maxCnt = *max_element(cntFor.begin(), cntFor.end());

        // dp[sz][cnt]: number of valid permutations of size sz and cnt inversions
        vector<vector<int>> dp(n + 1, vector<int>(maxCnt + 1));
        dp[1][0] = 1;

        for(int currSize = 1; currSize + 1 <= n; ++currSize){
            int startCnt = (cntFor[currSize] >= 0 ? cntFor[currSize] : 0);
            int endCnt = (cntFor[currSize] >= 0 ? cntFor[currSize] : maxCnt);
            for(int currCnt = startCnt; currCnt <= endCnt; ++currCnt){
                for(int newInv = 0; newInv <= currSize && currCnt + newInv <= maxCnt; ++newInv){
                    dp[currSize + 1][currCnt + newInv] += dp[currSize][currCnt];
                    dp[currSize + 1][currCnt + newInv] %= MODULO;
                }
            }
        }

        return dp[n][cntFor[n]];
    }
};