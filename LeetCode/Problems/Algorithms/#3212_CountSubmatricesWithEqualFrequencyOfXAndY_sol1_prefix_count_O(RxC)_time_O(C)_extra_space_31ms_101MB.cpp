class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        int res = 0;
        vector<int> vBalance(COLS);
        vector<int> vDots(COLS);

        for(int row = 0; row < ROWS; ++row){
            int prefBalance = 0;
            int prefDots = 0;
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == 'X'){
                    vBalance[col] += 1;
                }else if(grid[row][col] == 'Y'){
                    vBalance[col] -= 1;
                }else{
                    vDots[col] += 1;
                }
                prefBalance += vBalance[col];
                prefDots += vDots[col];
                if(prefBalance == 0 && prefDots != (row + 1) * (col + 1)){
                    res += 1;
                }
            }
        }

        return res;
    }
};