class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] % x != grid[0][0] % x){
                    return -1;
                }
            }
        }

        vector<int> sortedValues;
        sortedValues.reserve(ROWS * COLS);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                sortedValues.push_back(grid[row][col]);
            }
        }

        sort(sortedValues.begin(), sortedValues.end());

        int minOps = 0;
        int median = sortedValues[sortedValues.size() / 2];
        for(int val: sortedValues){
            minOps += abs(median - val) / x;
        }

        return minOps;
    }
};