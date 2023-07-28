class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        static const vector<pair<int, int>> DIRECTIONS = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
                                                          {2, -1}, {2, 1}, {1, -2}, {1, 2}};
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
                    for(const pair<int, int>& DIRECTION: DIRECTIONS){
                        int newRow = row + DIRECTION.first;
                        int newCol = col + DIRECTION.second;
                        if(0 <= newRow && newRow < n && 0 <= newCol && newCol < n){
                            newGrid[newRow][newCol] += grid[row][col] / 8.0;
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