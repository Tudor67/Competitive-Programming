class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        int res = 0;
        vector<int> vSum(COLS);

        for(int row = 0; row < ROWS; ++row){
            int prefSum = 0;
            for(int col = 0; col < COLS; ++col){
                vSum[col] += grid[row][col];
                prefSum += vSum[col];
                if(prefSum <= k){
                    res += 1;
                }
            }
        }

        return res;
    }
};