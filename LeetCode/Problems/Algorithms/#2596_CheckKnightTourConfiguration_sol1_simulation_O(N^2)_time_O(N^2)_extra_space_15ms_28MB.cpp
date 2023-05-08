class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        const int N = grid.size();
        
        if(grid[0][0] != 0){
            return false;
        }
        
        vector<pair<int, int>> positions(N * N);
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < N; ++col){
                positions[grid[row][col]] = {row, col};
            }
        }
        
        for(int i = 1; i < N * N; ++i){
            int dx = abs(positions[i].first - positions[i - 1].first);
            int dy = abs(positions[i].second - positions[i - 1].second);
            if(dx * dy != 2){
                return false;
            }
        }
        
        return true;
    }
};