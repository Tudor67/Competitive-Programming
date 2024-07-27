class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        const int N = grid.size();
        
        int repeatedVal = 0;
        vector<bool> vis(N * N + 1, false);
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < N; ++col){
                if(vis[grid[row][col]]){
                    repeatedVal = grid[row][col];
                }
                vis[grid[row][col]] = true;
            }
        }

        int missingVal = 0;
        for(int val = 1; val <= N * N; ++val){
            if(!vis[val]){
                missingVal = val;
            }
        }
        
        return {repeatedVal, missingVal};
    }
};