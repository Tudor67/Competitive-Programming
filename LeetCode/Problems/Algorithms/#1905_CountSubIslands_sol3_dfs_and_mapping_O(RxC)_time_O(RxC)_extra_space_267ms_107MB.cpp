class Solution {
private:
    const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    bool isInside(int row, int col, vector<vector<int>>& grid){
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        return (0 <= row && row < ROWS && 0 <= col && col < COLS);
    }

    void dfs(int row, int col, vector<vector<int>>& grid, int ccID, vector<vector<int>>& cc){
        if(!isInside(row, col, grid) || grid[row][col] == 0 || cc[row][col] != 0){
            return;
        }
        cc[row][col] = ccID;
        for(const pair<int, int>& DIRECTION: DIRECTIONS){
            dfs(row + DIRECTION.first, col + DIRECTION.second, grid, ccID, cc);
        }
    }

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        const int ROWS = grid1.size();
        const int COLS = grid1[0].size();

        int cc1ID = 0;
        int cc2ID = 0;
        vector<vector<int>> cc1(ROWS, vector<int>(COLS));
        vector<vector<int>> cc2(ROWS, vector<int>(COLS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid1[row][col] == 1 && cc1[row][col] == 0){
                    cc1ID += 1;
                    dfs(row, col, grid1, cc1ID, cc1);
                }
                if(grid2[row][col] == 1 && cc2[row][col] == 0){
                    cc2ID += 1;
                    dfs(row, col, grid2, cc2ID, cc2);
                }
            }
        }

        vector<int> firstPairOf(cc2ID + 1, -1);
        vector<int> secondPairOf(cc2ID + 1, -1);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(cc2[row][col] >= 1){
                    if(firstPairOf[cc2[row][col]] == -1 || firstPairOf[cc2[row][col]] == cc1[row][col]){
                        firstPairOf[cc2[row][col]] = cc1[row][col];
                    }else{
                        secondPairOf[cc2[row][col]] = cc1[row][col];
                    }
                }
            }
        }

        int subIslands = 0;
        for(int i = 0; i <= cc2ID; ++i){
            if(firstPairOf[i] >= 1 && secondPairOf[i] == -1){
                subIslands += 1;
            }
        }

        return subIslands;
    }
};