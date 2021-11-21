class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        const int ROWS = land.size();
        const int COLS = land[0].size();
        
        vector<vector<bool>> vis(ROWS, vector<bool>(COLS, false));
        vector<vector<int>> groups;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(land[row][col] == 1 && !vis[row][col]){
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
                            vis[i][j] = true;
                        }
                    }
                }
            }
        }
        
        return groups;
    }
};