class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        const int N = accounts.size();
        const int M = accounts[0].size();
        
        int maxWealth = 0;
        for(int i = 0; i < N; ++i){
            int wealth = 0;
            for(int j = 0; j < M; ++j){
                wealth += accounts[i][j];
            }
            maxWealth = max(maxWealth, wealth);
        }
        
        return maxWealth;
    }
};