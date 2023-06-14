class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        int res = 0;
        for(int row = 0; row < ROWS; ++row){
            if(grid[row][COLS - 1] < 0){
                int l = 0;
                int r = COLS - 1;
                while(l != r){
                    int mid = (l + r) / 2;
                    if(grid[row][mid] < 0){
                        r = mid;
                    }else{
                        l = mid + 1;
                    }
                }
                res += (COLS - r);
            }
        }

        return res;
    }
};