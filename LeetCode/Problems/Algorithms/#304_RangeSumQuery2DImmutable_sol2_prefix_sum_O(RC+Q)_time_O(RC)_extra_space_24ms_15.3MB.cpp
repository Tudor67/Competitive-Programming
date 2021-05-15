class NumMatrix {
private:
    vector<vector<int>> prefSum;
    
public:
    NumMatrix(vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        prefSum.resize(ROWS + 1, vector<int>(COLS + 1));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                prefSum[row + 1][col + 1] = matrix[row][col];
                prefSum[row + 1][col + 1] += prefSum[row][col + 1];
                prefSum[row + 1][col + 1] += prefSum[row + 1][col];
                prefSum[row + 1][col + 1] -= prefSum[row][col];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefSum[row2 + 1][col2 + 1] - prefSum[row2 + 1][col1] - prefSum[row1][col2 + 1] + prefSum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */