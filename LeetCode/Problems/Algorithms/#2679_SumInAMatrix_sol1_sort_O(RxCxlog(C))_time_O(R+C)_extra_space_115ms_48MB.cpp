class Solution {
public:
    int matrixSum(vector<vector<int>>& a) {
        const int ROWS = a.size();
        const int COLS = a[0].size();
        
        vector<int> sortedRow;
        vector<int> maxAtCol(COLS);
        for(int row = 0; row < ROWS; ++row){
            sortedRow = a[row];
            sort(sortedRow.begin(), sortedRow.end());

            for(int col = 0; col < COLS; ++col){
                maxAtCol[col] = max(maxAtCol[col], sortedRow[col]);
            }
        }
        
        return accumulate(maxAtCol.begin(), maxAtCol.end(), 0);
    }
};