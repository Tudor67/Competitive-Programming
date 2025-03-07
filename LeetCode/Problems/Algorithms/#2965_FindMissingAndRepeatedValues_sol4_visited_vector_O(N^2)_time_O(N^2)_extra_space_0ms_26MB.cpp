class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        const int N = grid.size();

        int duplicate = -1;
        int missing = -1;

        vector<bool> vis(N * N + 1, false);
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < N; ++col){
                if(vis[grid[row][col]]){
                    duplicate = grid[row][col];
                }
                vis[grid[row][col]] = true;
            }
        }

        for(int num = 1; num <= N * N; ++num){
            if(!vis[num]){
                missing = num;
                break;
            }
        }

        return {duplicate, missing};
    }
};