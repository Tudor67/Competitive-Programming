class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        const int N = jobDifficulty.size();
        const int INF = 1e9;
        
        if(N < d){
            return -1;
        }
        
        // minCost[i][x]: min cost to schedule jobs [0 .. i] in x days
        vector<vector<int>> minCost(N, vector<int>(d + 1, INF));
        minCost[0][1] = jobDifficulty[0];
        for(int i = 1; i < N; ++i){
            minCost[i][1] = max(minCost[i - 1][1], jobDifficulty[i]);
        }
        
        for(int days = 2; days <= d; ++days){
            for(int i = days - 1; i < N; ++i){
                int suffMax = 0;
                for(int j = i; j >= days - 1; --j){
                    suffMax = max(suffMax, jobDifficulty[j]);
                    minCost[i][days] = min(minCost[i][days], minCost[j - 1][days - 1] + suffMax);
                }
            }
        }
        
        return minCost[N - 1][d];
    }
};