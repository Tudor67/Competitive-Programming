class Solution {
private:
    void back(int level, int n, int visMaskCols, int visMaskMainDiags, int visMaskSecDiags,
              vector<string>& grid, vector<vector<string>>& solutions){
        if(level == n){
            solutions.push_back(grid);
        }else{
            int row = level;
            for(int col = 0; col < n; ++col){
                int mainDiagIdx = row - col + n;
                int secDiagIdx = row + col;
                if(!((visMaskCols >> col) & 1) && !((visMaskMainDiags >> mainDiagIdx) & 1) && !((visMaskSecDiags >> secDiagIdx) & 1)){
                    grid[row][col] = 'Q';
                    back(level + 1, n, visMaskCols | (1 << col), visMaskMainDiags | (1 << mainDiagIdx), visMaskSecDiags | (1 << secDiagIdx),
                         grid, solutions);
                    grid[row][col] = '.';
                }
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> grid(n, string(n, '.'));
        vector<vector<string>> solutions;
        back(0, n, 0, 0, 0, grid, solutions);
        return solutions;
    }
};