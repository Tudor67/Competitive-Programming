class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        const int ROWS = points.size();
        const int COLS = points[0].size();

        // At (row)th iteration:
        //    maxPoints[row % 2][col]: max points at cell (row, col)
        //                             when we start from the first row
        vector<vector<long long>> maxPoints(2, vector<long long>(COLS));
        for(int col = 0; col < COLS; ++col){
            maxPoints[0][col] = points[0][col];
        }

        for(int row = 1; row < ROWS; ++row){
            fill(maxPoints[row % 2].begin(), maxPoints[row % 2].end(), 0);
            for(int col = 0; col < COLS; ++col){
                for(int prevCol = 0; prevCol < COLS; ++prevCol){
                    maxPoints[row % 2][col] = max(maxPoints[row % 2][col],
                                                  maxPoints[(row - 1) % 2][prevCol] +
                                                  points[row][col] - abs(prevCol - col));
                }
            }
        }

        return *max_element(maxPoints[(ROWS - 1) % 2].begin(), maxPoints[(ROWS - 1) % 2].end());
    }
};