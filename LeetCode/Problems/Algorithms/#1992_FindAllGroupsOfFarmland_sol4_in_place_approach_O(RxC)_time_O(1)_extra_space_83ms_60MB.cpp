class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        const int ROWS = land.size();
        const int COLS = land[0].size();

        vector<vector<int>> res;
        for(int startRow = 0; startRow < ROWS; ++startRow){
            for(int startCol = 0; startCol < COLS; ++startCol){
                if(land[startRow][startCol] == 1){
                    int endRow = startRow;
                    int endCol = startCol;
                    while(endRow + 1 < ROWS && land[endRow + 1][endCol] == 1){
                        endRow += 1;
                    }
                    while(endCol + 1 < COLS && land[endRow][endCol + 1] == 1){
                        endCol += 1;
                    }
                    for(int row = startRow; row <= endRow; ++row){
                        for(int col = startCol; col <= endCol; ++col){
                            land[row][col] = -1;
                        }
                    }
                    res.push_back({startRow, startCol, endRow, endCol});
                }
            }
        }

        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(land[row][col] == -1){
                    land[row][col] = 1;
                }
            }
        }

        return res;
    }
};