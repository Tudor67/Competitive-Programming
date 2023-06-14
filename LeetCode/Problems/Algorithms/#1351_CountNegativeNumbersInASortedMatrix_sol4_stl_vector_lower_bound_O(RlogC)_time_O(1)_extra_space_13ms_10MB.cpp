class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        int res = 0;
        for(int row = 0; row < ROWS; ++row){
            if(grid[row][COLS - 1] < 0){
                vector<int>::iterator it = lower_bound(grid[row].begin(), grid[row].end(), -1,
                                                       [](int itVal, int val){
                                                           return itVal > val;
                                                       });
                res += (grid[row].end() - it);
            }
        }

        return res;
    }
};