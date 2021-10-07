class Solution {
private:
    const int INF = 1e8;
    
    int solve(int currentStateMask, const int& N, const int& K, vector<int>& preMask, vector<int>& dp){
        if(currentStateMask == 0){
            return 0;
        }
        if(dp[currentStateMask] != INF){
            return dp[currentStateMask];
        }
        int nodesToTakeMask = 0;
        for(int node = 0; node < N; ++node){
            if((currentStateMask >> node) & 1){
                if((~currentStateMask & preMask[node]) == preMask[node]){
                    nodesToTakeMask |= (1 << node);
                }
            }
        }
        int minCost = INF;
        for(int submask = nodesToTakeMask; submask > 0; submask = (submask - 1) & nodesToTakeMask){
            if(__builtin_popcount((unsigned int)submask) <= K){
                int cost = 1 + solve(currentStateMask - submask, N, K, preMask, dp);
                minCost = min(minCost, cost);
            }
        }
        dp[currentStateMask] = minCost;
        return minCost;
    }
    
public:
    int minNumberOfSemesters(int N, vector<vector<int>>& relations, int K) {
        if(relations.empty()){
            return (N + K - 1) / K;
        }
        
        vector<int> preMask(N, 0);
        for(const vector<int>& R: relations){
            int x = R[0] - 1;
            int y = R[1] - 1;
            preMask[y] |= (1 << x);
        }
        
        // dp[mask]: min semesters to take courses from mask
        const int FULL_MASK = (1 << N) - 1;
        vector<int> dp(FULL_MASK + 1, INF);
        return solve(FULL_MASK, N, K, preMask, dp);
    }
};