class NumMatrix {
private:
    vector<vector<int>> prefSum;
    
public:
    NumMatrix(vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        prefSum.assign(ROWS, vector<int>(COLS, 0));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                prefSum[row][col] = matrix[row][col];
                if(row - 1 >= 0){
                    prefSum[row][col] += prefSum[row - 1][col];
                }
                if(col - 1 >= 0){
                    prefSum[row][col] += prefSum[row][col - 1];
                }
                if(row - 1 >= 0 && col - 1 >= 0){
                    prefSum[row][col] -= prefSum[row - 1][col - 1];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = prefSum[row2][col2];
        if(row1 - 1 >= 0){
            sum -= prefSum[row1 - 1][col2];
        }
        if(col1 - 1 >= 0){
            sum -= prefSum[row2][col1 - 1];
        }
        if(row1 - 1 >= 0 && col1 - 1 >= 0){
            sum += prefSum[row1 - 1][col1 - 1];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */