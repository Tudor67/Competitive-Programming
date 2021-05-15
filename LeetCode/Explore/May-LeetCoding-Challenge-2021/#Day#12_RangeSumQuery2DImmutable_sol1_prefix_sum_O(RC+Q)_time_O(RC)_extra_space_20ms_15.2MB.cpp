class NumMatrix {
private:
    vector<vector<int>> prefSum;
    
    int getVal(const vector<vector<int>>& A, int row, int col){
        if(0 <= row && row < (int)A.size() && 0 <= col && col < (int)A[row].size()){
            return A[row][col];
        }
        return 0;
    }
    
public:
    NumMatrix(vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        prefSum = matrix;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                prefSum[row][col] += getVal(prefSum, row - 1, col);
                prefSum[row][col] += getVal(prefSum, row, col - 1);
                prefSum[row][col] -= getVal(prefSum, row - 1, col - 1);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return getVal(prefSum, row2, col2) - getVal(prefSum, row2, col1 - 1) -
               getVal(prefSum, row1 - 1, col2) + getVal(prefSum, row1 - 1, col1 - 1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */