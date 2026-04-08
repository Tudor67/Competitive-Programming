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

        // Case 1: COLS = 1
        if(COLS == 1){
            long long prefSum = 0;
            for(int row = 0; row < ROWS; ++row){
                prefSum += A[row][0];
                if(prefSum == totalSum - prefSum ||
                   prefSum - A[0][0] == totalSum - prefSum ||
                   prefSum - A[row][0] == totalSum - prefSum){
                    return true;
                }
            }
            return false;
        }

        // Case 2: COLS >= 2
        // Case 2.1: check the first row
        long long firstRowSum = accumulate(A[0].begin(), A[0].end(), (long long)0);
        if(firstRowSum == totalSum - firstRowSum ||
           firstRowSum - A[0][0] == totalSum - firstRowSum ||
           firstRowSum - A[0][COLS - 1] == totalSum - firstRowSum){
            return true;
        }

        // Case 2.2: check the remaining rows
        long long prefSum = totalSum;
        unordered_set<long long> s;
        for(int row = ROWS - 1; row >= 0; --row){
            if(prefSum == totalSum - prefSum){
                return true;
            }
            if(row >= 1){
                s.insert(2 * prefSum - totalSum);
            }
            for(int col = 0; col < COLS; ++col){
                if(s.contains(A[row][col])){
                    return true;
                }
            }
            for(int col = 0; col < COLS; ++col){
                prefSum -= A[row][col];
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