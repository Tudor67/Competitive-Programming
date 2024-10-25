class Solution {
private:
    int getVal(vector<vector<int>>& a, int row, int col){
        if(min(row, col) >= 0){
            return a[row][col];
        }
        return 0;
    }

public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        int validSubmatrices = 0;
        vector<vector<int>> prefSum(2, vector<int>(COLS));

        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                prefSum[row % 2][col] = grid[row][col]
                                        + getVal(prefSum, (row - 1) % 2, col)
                                        + getVal(prefSum, row % 2, col - 1)
                                        - getVal(prefSum, (row - 1) % 2, col - 1);
                if(prefSum[row % 2][col] <= k){
                    validSubmatrices += 1;
                }
            }
        }
        
        return validSubmatrices;
    }
};