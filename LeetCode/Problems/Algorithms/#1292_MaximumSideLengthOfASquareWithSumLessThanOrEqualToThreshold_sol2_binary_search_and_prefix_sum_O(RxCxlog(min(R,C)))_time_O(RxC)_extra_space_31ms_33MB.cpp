class Solution {
private:
    int getVal(vector<vector<int>>& mat, int row, int col){
        if(0 <= row && row < (int)mat.size() && 0 <= col && col < (int)mat[0].size()){
            return mat[row][col];
        }
        return 0;
    }

    bool containsValidSquare(vector<vector<int>>& prefSum, int threshold, int targetSqSide){
        const int ROWS = prefSum.size();
        const int COLS = prefSum[0].size();

        if(targetSqSide == 0){
            return true;
        }

        for(int startRow = 0; startRow + targetSqSide - 1 < ROWS; ++startRow){
            for(int startCol = 0; startCol + targetSqSide - 1 < COLS; ++startCol){
                int sum = prefSum[startRow + targetSqSide - 1][startCol + targetSqSide - 1]
                          - getVal(prefSum, startRow + targetSqSide - 1, startCol - 1)
                          - getVal(prefSum, startRow - 1, startCol + targetSqSide - 1)
                          + getVal(prefSum, startRow - 1, startCol - 1);
                if(sum <= threshold){
                    return true;
                }
            }
        }

        return false;
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

        int l = 0;
        int r = min(ROWS, COLS);
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(containsValidSquare(prefSum, threshold, mid)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }

        return r;
    }
};