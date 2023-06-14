class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        int res = 0;
        for(int row = 0; row < ROWS; ++row){
            if(grid[row][COLS - 1] < 0){
                vector<int>::reverse_iterator it = upper_bound(grid[row].rbegin(), grid[row].rend(), -1);
                res += (it - grid[row].rbegin());
            }
        }

        return res;
    }
};