class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        const int ROWS = land.size();
        const int COLS = land[0].size();
        const int VIS_MARK = 2;
        
        vector<vector<int>> groups;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(land[row][col] == 1){
                    int rowLen = 1;
                    while(row + rowLen < ROWS && land[row + rowLen][col] == 1){
                        ++rowLen;
                    }
                    int colLen = 1;
                    while(col + colLen < COLS && land[row][col + colLen] == 1){
                        ++colLen;
                    }
                    groups.push_back({row, col, row + rowLen - 1, col + colLen - 1});
                    for(int i = row; i <= row + rowLen - 1; ++i){
                        for(int j = col; j <= col + colLen - 1; ++j){
                            land[i][j] = VIS_MARK;
                        }
                    }
                }
            }
        }
        
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(land[row][col] == VIS_MARK){
                    land[row][col] = 1;
                }
            }
        }
        
        return groups;
    }
};