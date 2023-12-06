class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        vector<vector<int>> res(ROWS, vector<int>(COLS));
        
        for(int startRow = 0; startRow < ROWS; ++startRow){
            for(int startCol = 0; startCol < COLS; ++startCol){
                if(startRow == 0 || startCol == 0){
                    int row = startRow;
                    int col = startCol;
                    unordered_set<int> vis;
                    while(row < ROWS && col < COLS){
                        vis.insert(grid[row][col]);
                        if(row + 1 < ROWS && col + 1 < COLS){
                            res[row + 1][col + 1] = vis.size();
                        }
                        row += 1;
                        col += 1;
                    }
                    
                    row -= 1;
                    col -= 1;
                    vis.clear();
                    while(row >= 0 && col >= 0){
                        vis.insert(grid[row][col]);
                        if(row - 1 >= 0 && col - 1 >= 0){
                            res[row - 1][col - 1] = abs(res[row - 1][col - 1] - (int)vis.size());
                        }
                        row -= 1;
                        col -= 1;
                    }
                }
            }
        }
        
        return res;
    }
};