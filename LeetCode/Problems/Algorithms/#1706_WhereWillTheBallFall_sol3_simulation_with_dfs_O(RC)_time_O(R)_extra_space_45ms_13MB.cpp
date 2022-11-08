class Solution {
private:
    int dfs(int row, int col, vector<vector<int>>& grid){
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        if(row == ROWS){
            return col;
        }
        
        if(col - 1 >= 0 && grid[row][col - 1] == -1 && grid[row][col] == -1){
            return dfs(row + 1, col - 1, grid);
        }
        
        if(col + 1 < COLS && grid[row][col] == 1 && grid[row][col + 1] == 1){
            return dfs(row + 1, col + 1, grid);
        }
        
        return -1;
    }
    
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        vector<int> answer(COLS);
        for(int col = 0; col < COLS; ++col){
            answer[col] = dfs(0, col, grid);
        }
        
        return answer;
    }
};