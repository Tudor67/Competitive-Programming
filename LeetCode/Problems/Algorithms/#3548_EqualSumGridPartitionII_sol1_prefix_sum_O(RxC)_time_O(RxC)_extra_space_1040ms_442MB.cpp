class Solution {
private:
    bool canPartitionHorizontally(const vector<vector<int>>& A){
        const int ROWS = A.size();
        const int COLS = A[0].size();

        long long totalSum = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                totalSum += A[row][col];
            }
        }

        long long prefSum = 0;
        unordered_set<long long> targetSums;
        targetSums.insert(totalSum);

        for(int row = 0; row < ROWS; ++row){
            if(row == 0){
                targetSums.insert(totalSum + A[0][0]);
                targetSums.insert(totalSum + A[0][COLS - 1]);
            }else if(row == 1){
                for(int col = 0; col < COLS; ++col){
                    targetSums.insert(totalSum + A[0][col]);
                    targetSums.insert(totalSum + A[1][col]);
                }
            }else{
                for(int col = 0; col < COLS; ++col){
                    targetSums.insert(totalSum + A[row][col]);
                }
            }

            for(int col = 0; col < COLS; ++col){
                prefSum += A[row][col];
            }

            if(COLS == 1){
                if(2 * prefSum == totalSum ||
                   2 * prefSum == totalSum + A[0][0] ||
                   2 * prefSum == totalSum + A[row][0]){
                    return true;
                }
            }else if(targetSums.contains(2 * prefSum)){
                return true;
            }
        }

        return false;
    }

public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        vector<vector<int>> A(ROWS, vector<int>(COLS));
        vector<vector<int>> A_REV(ROWS, vector<int>(COLS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                A[row][col] = grid[row][col];
                A_REV[ROWS - 1 - row][col] = A[row][col];
            }
        }

        vector<vector<int>> A_T(COLS, vector<int>(ROWS));
        vector<vector<int>> A_T_REV(COLS, vector<int>(ROWS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                A_T[col][row] = A[row][col];
                A_T_REV[COLS - 1 - col][row] = A_T[col][row];
            }
        }

        return canPartitionHorizontally(A) || canPartitionHorizontally(A_REV) ||
               canPartitionHorizontally(A_T) || canPartitionHorizontally(A_T_REV);
    }
};