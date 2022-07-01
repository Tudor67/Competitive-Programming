class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        set<int> maxSums3;
        for(int centerRow = 0; centerRow < ROWS; ++centerRow){
            for(int centerCol = 0; centerCol < COLS; ++centerCol){
                for(int delta = 0; delta <= min({centerCol, COLS - 1 - centerCol, centerRow, ROWS - 1 - centerRow}); ++delta){
                    int sum = grid[centerRow - delta][centerCol] + (int)(delta >= 1) * grid[centerRow + delta][centerCol];
                    int row = centerRow;
                    for(int col1 = centerCol - delta, col2 = centerCol + delta; col1 < col2; ++col1, --col2){
                        sum += grid[row][col1];
                        sum += grid[row][col2];
                        row -= 1;
                    }
                    
                    row = centerRow + 1;
                    for(int col1 = centerCol - delta + 1, col2 = centerCol + delta - 1; col1 < col2; ++col1, --col2){
                        sum += grid[row][col1];
                        sum += grid[row][col2];
                        row += 1;
                    }
                    
                    maxSums3.insert(sum);
                    if((int)maxSums3.size() > 3){
                        maxSums3.erase(maxSums3.begin());
                    }
                }
            }
        }
        
        return vector<int>(maxSums3.rbegin(), maxSums3.rend());
    }
};