class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        vector<int> values;
        values.reserve(ROWS * COLS);

        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if((grid[0][0] % x) != (grid[row][col] % x)){
                    return -1;
                }
                values.push_back(grid[row][col]);
            }
        }

        nth_element(values.begin(), values.begin() + values.size() / 2, values.end());

        int median = values[values.size() / 2];
        int totalOps = 0;
        for(int val: values){
            totalOps += abs(median - val) / x;
        }
        
        return totalOps;
    }
};