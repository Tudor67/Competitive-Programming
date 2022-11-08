class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        vector<int> prevIndices(COLS);
        iota(prevIndices.begin(), prevIndices.end(), 0);
        
        vector<int> indices = prevIndices;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(col >= 1 && grid[row][col - 1] == 1 && grid[row][col] == 1){
                    indices[col] = prevIndices[col - 1];
                }else if(col + 1 < COLS && grid[row][col] == -1 && grid[row][col + 1] == -1){
                    indices[col] = prevIndices[col + 1];
                }else{
                    indices[col] = -1;
                }
            }
            prevIndices = indices;
        }
        
        vector<int> answer(COLS, -1);
        for(int col = 0; col < COLS; ++col){
            if(indices[col] >= 0){
                answer[indices[col]] = col;
            }
        }
        
        return answer;
    }
};