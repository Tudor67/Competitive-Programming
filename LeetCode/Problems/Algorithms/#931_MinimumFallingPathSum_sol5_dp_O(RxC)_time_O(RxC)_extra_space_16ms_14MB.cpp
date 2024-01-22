class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        const vector<pair<int, int>> DIRECTIONS = {{-1, -1}, {-1, 0}, {-1, 1}};
        const int INF = 1e9;

        // minSum[row][col]: min sum of a falling path with the last cell (row, col)
        vector<vector<int>> minSum(ROWS, vector<int>(COLS, INF));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(row == 0){
                    minSum[row][col] = matrix[row][col];
                }else{
                    for(const pair<int, int>& DIRECTION: DIRECTIONS){
                        int prevRow = row + DIRECTION.first;
                        int prevCol = col + DIRECTION.second;
                        if(0 <= prevRow && prevRow < ROWS && 0 <= prevCol && prevCol < COLS){
                            minSum[row][col] = min(minSum[row][col], minSum[prevRow][prevCol] + matrix[row][col]);
                        }
                    }
                }
            }
        }

        return *min_element(minSum[ROWS - 1].begin(), minSum[ROWS - 1].end());
    }
};