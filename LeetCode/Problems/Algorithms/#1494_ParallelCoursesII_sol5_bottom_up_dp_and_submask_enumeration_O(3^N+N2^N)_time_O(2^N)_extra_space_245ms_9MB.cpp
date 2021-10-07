class Solution {
public:
    int minNumberOfSemesters(int N, vector<vector<int>>& relations, int K) {
        if(relations.empty()){
            return (N + K - 1) / K;
        }
        
        const int FULL_MASK = (1 << N) - 1;
        const int INF = 1e8;
        
        vector<int> preMask(N, 0);
        for(const vector<int>& R: relations){
            int x = R[0] - 1;
            int y = R[1] - 1;
            preMask[y] |= (1 << x);
        }
        
        // dp[mask]: min semesters to take courses from mask
        vector<int> dp(FULL_MASK + 1, INF);
        dp[0] = 0;
        for(int currentStateMask = 0; currentStateMask <= FULL_MASK; ++currentStateMask){
            if(dp[currentStateMask] == INF){
                continue;
            }
            int newNodesMask = 0;
            for(int node = 0; node < N; ++node){
                if(!((currentStateMask >> node) & 1)){
                    if((currentStateMask & preMask[node]) == preMask[node]){
                        newNodesMask |= (1 << node);
                    }
                }
            }
            for(int newNodesSubmask = newNodesMask; newNodesSubmask > 0; newNodesSubmask = (newNodesSubmask - 1) & newNodesMask){
                if(__builtin_popcount((unsigned int)newNodesSubmask) <= K){
                    dp[currentStateMask | newNodesSubmask] = min(dp[currentStateMask | newNodesSubmask], dp[currentStateMask] + 1);
                }
            }
        }
        
        return dp[FULL_MASK];
    }
};