class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampRows, int stampCols) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        int h[ROWS][COLS];
        bool can[ROWS][COLS];
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == 0){
                    h[row][col] = 1;
                    if(row - 1 >= 0){
                        h[row][col] += h[row - 1][col];
                    }
                }else{
                    h[row][col] = 0;
                }
                can[row][col] = false;
            }
        }
        
        deque<int> dq;
        for(int row = stampRows - 1; row < ROWS; ++row){
            dq.clear();
            for(int col = 0; col < COLS; ++col){
                while(!dq.empty() && col - dq.front() + 1 > stampCols){
                    dq.pop_front();
                }
                while(!dq.empty() && h[row][dq.back()] >= h[row][col]){
                    dq.pop_back();
                }
                dq.push_back(col);

                if(col >= stampCols - 1 && h[row][dq.front()] >= stampRows){
                    for(int i = row; i >= row - stampRows + 1 && !can[i][col]; --i){
                        for(int j = col; j >= col - stampCols + 1 && !can[i][j]; --j){
                            can[i][j] = true;
                        }
                    }
                    for(int i = row - stampRows + 1; i <= row && !can[i][col - stampCols + 1]; ++i){
                        for(int j = col - stampCols + 1; j <= col && !can[i][j]; ++j){
                            can[i][j] = true;
                        }
                    }
                }
            }
        }
        
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == 0 && !can[row][col]){
                    return false;
                }
            }
        }
        
        return true;
    }
};