class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.empty()){
            return 0;
        }
        
        const int N = grid.size();
        const int M = grid[0].size();
        
        int h_lines = 0;
        for(int i = 0; i < N; ++i){
            int prev_val = 0;
            for(int j = 0; j < M; ++j){
                h_lines += (prev_val != grid[i][j]);
                prev_val = grid[i][j];
            }
            h_lines += (grid[i][M - 1] == 1);
        }
        
        int v_lines = 0;
        for(int j = 0; j < M; ++j){
            int prev_val = 0;
            for(int i = 0; i < N; ++i){
                v_lines += (prev_val != grid[i][j]);
                prev_val = grid[i][j];
            }
            v_lines += (grid[N - 1][j] == 1);
        }
        
        return h_lines + v_lines;
    }
};