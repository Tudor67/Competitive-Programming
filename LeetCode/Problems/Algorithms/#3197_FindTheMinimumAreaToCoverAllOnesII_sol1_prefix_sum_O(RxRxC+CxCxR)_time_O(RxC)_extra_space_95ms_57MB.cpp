class Solution {
private:
    vector<vector<int>> reverseEachRow(const vector<vector<int>>& grid){
        vector<vector<int>> res = grid;
        for(int row = 0; row < (int)res.size(); ++row){
            reverse(res[row].begin(), res[row].end());
        }
        return res;
    }

    vector<vector<int>> rotate90(const vector<vector<int>>& grid){
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        vector<vector<int>> res(COLS, vector<int>(ROWS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                res[col][row] = grid[row][col];
            }
        }
        return reverseEachRow(res);
    }

    void updateMinMax(int val, int row, int col, int& minRow, int& maxRow, int& minCol, int& maxCol){
        if(val == 1){
            minRow = min(minRow, row);
            maxRow = max(maxRow, row);
            minCol = min(minCol, col);
            maxCol = max(maxCol, col);
        }
    }

    int computeArea(int minRow, int maxRow, int minCol, int maxCol){
        if(min(maxRow, maxCol) < 0){
            return 0;
        }
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }

    int computeMinArea(const vector<vector<int>>& grid){
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int INF = 1e9;

        int minArea = ROWS * COLS;

        vector<vector<int>> minRowRU(ROWS, vector<int>(COLS + 1, INF));
        vector<vector<int>> maxRowRU(ROWS, vector<int>(COLS + 1, -1));
        vector<vector<int>> minColRU(ROWS, vector<int>(COLS + 1, INF));
        vector<vector<int>> maxColRU(ROWS, vector<int>(COLS + 1, -1));
        for(int row = 0; row < ROWS; ++row){
            for(int col = COLS - 1; col >= 0; --col){
                if(row - 1 >= 0){
                    minRowRU[row][col] = min(minRowRU[row][col], minRowRU[row - 1][col]);
                    maxRowRU[row][col] = max(maxRowRU[row][col], maxRowRU[row - 1][col]);
                    minColRU[row][col] = min(minColRU[row][col], minColRU[row - 1][col]);
                    maxColRU[row][col] = max(maxColRU[row][col], maxColRU[row - 1][col]);
                }
                if(col + 1 < COLS){
                    minRowRU[row][col] = min(minRowRU[row][col], minRowRU[row][col + 1]);
                    maxRowRU[row][col] = max(maxRowRU[row][col], maxRowRU[row][col + 1]);
                    minColRU[row][col] = min(minColRU[row][col], minColRU[row][col + 1]);
                    maxColRU[row][col] = max(maxColRU[row][col], maxColRU[row][col + 1]);
                }
                updateMinMax(grid[row][col], row, col, minRowRU[row][col], maxRowRU[row][col],
                                                       minColRU[row][col], maxColRU[row][col]);
            }
        }

        vector<vector<int>> minRowLU(ROWS, vector<int>(COLS, INF));
        vector<vector<int>> maxRowLU(ROWS, vector<int>(COLS, -1));
        vector<vector<int>> minColLU(ROWS, vector<int>(COLS, INF));
        vector<vector<int>> maxColLU(ROWS, vector<int>(COLS, -1));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(row - 1 >= 0){
                    minRowLU[row][col] = min(minRowLU[row][col], minRowLU[row - 1][col]);
                    maxRowLU[row][col] = max(maxRowLU[row][col], maxRowLU[row - 1][col]);
                    minColLU[row][col] = min(minColLU[row][col], minColLU[row - 1][col]);
                    maxColLU[row][col] = max(maxColLU[row][col], maxColLU[row - 1][col]);
                }
                if(col - 1 >= 0){
                    minRowLU[row][col] = min(minRowLU[row][col], minRowLU[row][col - 1]);
                    maxRowLU[row][col] = max(maxRowLU[row][col], maxRowLU[row][col - 1]);
                    minColLU[row][col] = min(minColLU[row][col], minColLU[row][col - 1]);
                    maxColLU[row][col] = max(maxColLU[row][col], maxColLU[row][col - 1]);
                }
                updateMinMax(grid[row][col], row, col, minRowLU[row][col], maxRowLU[row][col],
                                                       minColLU[row][col], maxColLU[row][col]);
            }
        }

        vector<vector<int>> minRowLD(ROWS + 1, vector<int>(COLS, INF));
        vector<vector<int>> maxRowLD(ROWS + 1, vector<int>(COLS, -1));
        vector<vector<int>> minColLD(ROWS + 1, vector<int>(COLS, INF));
        vector<vector<int>> maxColLD(ROWS + 1, vector<int>(COLS, -1));
        for(int row = ROWS - 1; row >= 0; --row){
            for(int col = 0; col < COLS; ++col){
                if(row + 1 < ROWS){
                    minRowLD[row][col] = min(minRowLD[row][col], minRowLD[row + 1][col]);
                    maxRowLD[row][col] = max(maxRowLD[row][col], maxRowLD[row + 1][col]);
                    minColLD[row][col] = min(minColLD[row][col], minColLD[row + 1][col]);
                    maxColLD[row][col] = max(maxColLD[row][col], maxColLD[row + 1][col]);
                }
                if(col - 1 >= 0){
                    minRowLD[row][col] = min(minRowLD[row][col], minRowLD[row][col - 1]);
                    maxRowLD[row][col] = max(maxRowLD[row][col], maxRowLD[row][col - 1]);
                    minColLD[row][col] = min(minColLD[row][col], minColLD[row][col - 1]);
                    maxColLD[row][col] = max(maxColLD[row][col], maxColLD[row][col - 1]);
                }
                updateMinMax(grid[row][col], row, col, minRowLD[row][col], maxRowLD[row][col],
                                                       minColLD[row][col], maxColLD[row][col]);
            }
        }

        for(int col1 = 0; col1 < COLS; ++col1){
            int minRow2 = INF;
            int maxRow2 = -1;
            int minCol2 = INF;
            int maxCol2 = -1;
            for(int col2 = col1 + 1; col2 < COLS; ++col2){
                for(int row = 0; row < ROWS; ++row){
                    updateMinMax(grid[row][col2], row, col2, minRow2, maxRow2, minCol2, maxCol2);
                }
                int area1 = computeArea(minRowLU[ROWS - 1][col1], maxRowLU[ROWS - 1][col1],
                                        minColLU[ROWS - 1][col1], maxColLU[ROWS - 1][col1]);
                int area2 = computeArea(minRow2, maxRow2, minCol2, maxCol2);
                int area3 = computeArea(minRowRU[ROWS - 1][col2 + 1], maxRowRU[ROWS - 1][col2 + 1],
                                        minColRU[ROWS - 1][col2 + 1], maxColRU[ROWS - 1][col2 + 1]);
                minArea = min(minArea, area1 + area2 + area3);
            }

            for(int row = 0; row < ROWS && col1 - 1 >= 0; ++row){
                int area1 = computeArea(minRowLU[row][col1 - 1], maxRowLU[row][col1 - 1],
                                        minColLU[row][col1 - 1], maxColLU[row][col1 - 1]);
                int area2 = computeArea(minRowLD[row + 1][col1 - 1], maxRowLD[row + 1][col1 - 1],
                                        minColLD[row + 1][col1 - 1], maxColLD[row + 1][col1 - 1]);
                int area3 = computeArea(minRowRU[ROWS - 1][col1], maxRowRU[ROWS - 1][col1],
                                        minColRU[ROWS - 1][col1], maxColRU[ROWS - 1][col1]);
                minArea = min(minArea, area1 + area2 + area3);
            }
        }

        return minArea;
    }

public:
    int minimumSum(vector<vector<int>>& grid) {
        return min({computeMinArea(grid), computeMinArea(reverseEachRow(grid)),
                    computeMinArea(rotate90(grid)), computeMinArea(reverseEachRow(rotate90(grid)))});
    }
};