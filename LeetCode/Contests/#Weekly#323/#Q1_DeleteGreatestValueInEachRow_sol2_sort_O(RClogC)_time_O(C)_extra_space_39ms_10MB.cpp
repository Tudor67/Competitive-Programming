class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        vector<int> maxAtStep(COLS);
        vector<int> sortedRow(COLS);
        for(int row = 0; row < ROWS; ++row){
            copy(grid[row].begin(), grid[row].end(), sortedRow.begin());
            sort(sortedRow.rbegin(), sortedRow.rend());
            for(int col = 0; col < COLS; ++col){
                maxAtStep[col] = max(maxAtStep[col], sortedRow[col]);
            }
        }

        return accumulate(maxAtStep.begin(), maxAtStep.end(), 0);
    }
};