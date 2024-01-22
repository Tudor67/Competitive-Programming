class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        const vector<pair<int, int>> DIRECTIONS = {{-1, -1}, {-1, 0}, {-1, 1}};
        const int INF = 1e9;

        // At (row)th iteration:
        //    minSum[row % 2][col]: min sum of a falling path with the last cell (row, col)
        vector<vector<int>> minSum(2, vector<int>(COLS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(row == 0){
                    minSum[row % 2][col] = matrix[row][col];
                }else{
                    minSum[row % 2][col] = INF;
                    for(const pair<int, int>& DIRECTION: DIRECTIONS){
                        int prevRow = row + DIRECTION.first;
                        int prevCol = col + DIRECTION.second;
                        if(0 <= prevRow && prevRow < ROWS && 0 <= prevCol && prevCol < COLS){
                            minSum[row % 2][col] = min(minSum[row % 2][col], minSum[prevRow % 2][prevCol] + matrix[row][col]);
                        }
                    }
                }
            }
        }

        return *min_element(minSum[(ROWS - 1) % 2].begin(), minSum[(ROWS - 1) % 2].end());
    }
};