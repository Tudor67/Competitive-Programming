class Solution {
private:
    int countLessOrEqual(vector<vector<int>>& grid, int threshold){
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        int count = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] <= threshold){
                    count += 1;
                }
            }
        }

        return count;
    }

public:
    int minOperations(vector<vector<int>>& grid, int x) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        // Step 1: check if it is possible to make the grid uni-value
        int minVal = grid[0][0];
        int maxVal = grid[0][0];
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if((grid[0][0] % x) != (grid[row][col] % x)){
                    return -1;
                }
                minVal = min(minVal, grid[row][col]);
                maxVal = max(maxVal, grid[row][col]);
            }
        }

        // Step 2: binary search the median of grid
        int l = minVal;
        int r = maxVal;
        while(l != r){
            int mid = (l + r) / 2;
            if(countLessOrEqual(grid, mid) < (ROWS * COLS) / 2 + 1){
                l = mid + 1;
            }else{
                r = mid;
            }
        }

        int median = r;

        // Step 3: compute the total distance to median
        int totalOps = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                totalOps += abs(median - grid[row][col]) / x;
            }
        }
        
        return totalOps;
    }
};