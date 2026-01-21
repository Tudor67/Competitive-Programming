class Solution {
private:
    int getVal(vector<vector<int>>& mat, int row, int col){
        if(0 <= row && row < (int)mat.size() && 0 <= col && col < (int)mat[0].size()){
            return mat[row][col];
        }
        return 0;
    }

public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        const int ROWS = mat.size();
        const int COLS = mat[0].size();

        vector<vector<int>> prefSum(ROWS, vector<int>(COLS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                prefSum[row][col] = mat[row][col]
                                    + getVal(prefSum, row - 1, col)
                                    + getVal(prefSum, row, col - 1)
                                    - getVal(prefSum, row - 1, col - 1);
            }
        }

        int res = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                for(int side = res + 1; side <= min(ROWS, COLS); ++side){
                    if(row + side - 1 < ROWS && col + side - 1 < COLS &&
                       prefSum[row + side - 1][col + side - 1]
                       - getVal(prefSum, row + side - 1, col - 1)
                       - getVal(prefSum, row - 1, col + side - 1)
                       + getVal(prefSum, row - 1, col - 1) <= threshold){
                        res += 1;
                    }else{
                        break;
                    }
                }
            }
        }

        return res;
    }
};