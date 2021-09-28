class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        
        vector<int> spiralValues;
        int minRow = 0, maxRow = ROWS - 1;
        int minCol = 0, maxCol = COLS - 1;
        while((int)spiralValues.size() < ROWS * COLS){
            for(int col = minCol; col <= maxCol; ++col){
                spiralValues.push_back(matrix[minRow][col]);
            }
            minRow += 1;
            for(int row = minRow; row <= maxRow; ++row){
                spiralValues.push_back(matrix[row][maxCol]);
            }
            maxCol -= 1;
            for(int col = maxCol; minRow <= maxRow && col >= minCol; --col){
                spiralValues.push_back(matrix[maxRow][col]);
            }
            maxRow -= 1;
            for(int row = maxRow; minCol <= maxCol && row >= minRow; --row){
                spiralValues.push_back(matrix[row][minCol]);
            }
            minCol += 1;
        }
        
        return spiralValues;
    }
};