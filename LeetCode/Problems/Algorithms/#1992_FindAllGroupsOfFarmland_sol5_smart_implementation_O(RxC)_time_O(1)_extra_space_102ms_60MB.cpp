class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        const int ROWS = land.size();
        const int COLS = land[0].size();

        vector<vector<int>> res;
        for(int startRow = 0; startRow < ROWS; ++startRow){
            for(int startCol = 0; startCol < COLS; ++startCol){
                if((land[startRow][startCol] == 1) &&
                   (startRow == 0 || land[startRow - 1][startCol] == 0) &&
                   (startCol == 0 || land[startRow][startCol - 1] == 0)){
                    int endRow = startRow;
                    int endCol = startCol;
                    while(endRow + 1 < ROWS && land[endRow + 1][endCol] == 1){
                        endRow += 1;
                    }
                    while(endCol + 1 < COLS && land[endRow][endCol + 1] == 1){
                        endCol += 1;
                    }
                    res.push_back({startRow, startCol, endRow, endCol});
                }
            }
        }

        return res;
    }
};