class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int FULL_MASK = (1 << COLS) - 1;
        
        vector<int> maskToRow(FULL_MASK + 1, -1);
        for(int row = 0; row < ROWS; ++row){
            int mask = 0;
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == 1){
                    mask |= (1 << col);
                }
            }
            maskToRow[mask] = row;
        }
        
        if(maskToRow[0] != -1){
            return {maskToRow[0]};
        }
        
        for(int mask1 = 1; mask1 <= FULL_MASK; ++mask1){
            for(int mask2 = 1; mask2 <= FULL_MASK; ++mask2){
                if(maskToRow[mask1] != -1 && maskToRow[mask2] != -1){
                    if((mask1 & mask2) == 0){
                        return {min(maskToRow[mask1], maskToRow[mask2]),
                                max(maskToRow[mask1], maskToRow[mask2])};
                    }
                }
            }
        }
        
        return {};
    }
};