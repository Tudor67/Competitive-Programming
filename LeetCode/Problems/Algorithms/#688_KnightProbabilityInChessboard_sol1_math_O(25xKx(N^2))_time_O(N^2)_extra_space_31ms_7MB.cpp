class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> grid(n, vector<double>(n));
        vector<vector<double>> newGrid(n, vector<double>(n));
        grid[row][column] = 1;

        for(int step = 1; step <= k; ++step){
            for(int row = 0; row < n; ++row){
                for(int col = 0; col < n; ++col){
                    newGrid[row][col] = 0;
                }
            }
            for(int row = 0; row < n; ++row){
                for(int col = 0; col < n; ++col){
                    for(int rowDelta = -2; rowDelta <= 2; ++rowDelta){
                        for(int colDelta = -2; colDelta <= 2; ++colDelta){
                            int newRow = row + rowDelta;
                            int newCol = col + colDelta;
                            if(min(abs(rowDelta), abs(colDelta)) == 1 &&
                               max(abs(rowDelta), abs(colDelta)) == 2 &&
                               0 <= newRow && newRow < n && 0 <= newCol && newCol < n){
                                newGrid[newRow][newCol] += grid[row][col] / 8.0;
                            }
                        }
                    }
                }
            }
            grid = newGrid;
        }

        double res = 0;
        for(int row = 0; row < n; ++row){
            for(int col = 0; col < n; ++col){
                res += grid[row][col];
            }
        }

        return res;
    }
};