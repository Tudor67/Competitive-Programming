class Solution {
private:
    int getMaxOfCol(vector<vector<int>>& matrix, int col){
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        int maxVal = matrix[0][col];
        for(int row = 0; row < ROWS; ++row){
            maxVal = max(maxVal, matrix[row][col]);
        }
        return maxVal;
    }

public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();

        for(int row = 0; row < ROWS; ++row){
            int col = min_element(matrix[row].begin(), matrix[row].end()) - matrix[row].begin();
            if(matrix[row][col] == getMaxOfCol(matrix, col)){
                return {matrix[row][col]};
            }
        }

        return {};
    }
};