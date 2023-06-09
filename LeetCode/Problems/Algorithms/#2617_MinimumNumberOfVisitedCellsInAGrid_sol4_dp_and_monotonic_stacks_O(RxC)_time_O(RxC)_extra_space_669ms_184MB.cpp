class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int INF = 1e9;

        vector<vector<int>> dist(ROWS, vector<int>(COLS, INF));
        vector<vector<array<int, 2>>> availAtCol(COLS);
        vector<array<int, 2>> availAtCurrentRow(COLS);
        dist[ROWS - 1][COLS - 1] = 1;
        
        for(int row = ROWS - 1; row >= 0; --row){
            availAtCurrentRow.clear();
            for(int col = COLS - 1; col >= 0; --col){
                if(row == ROWS - 1 && col == COLS - 1){
                    availAtCol[col].push_back({row, 1});
                    availAtCurrentRow.push_back({col, 1});
                }else{
                    int size = availAtCol[col].size();
                    while(size >= 2 && availAtCol[col][size - 2][0] <= row + grid[row][col]){
                        availAtCol[col].pop_back();
                        size -= 1;
                    }

                    size = availAtCurrentRow.size();
                    while(size >= 2 && availAtCurrentRow[size - 2][0] <= col + grid[row][col]){
                        availAtCurrentRow.pop_back();
                        size -= 1;
                    }

                    if(!availAtCol[col].empty() && availAtCol[col].back()[0] <= row + grid[row][col]){
                        dist[row][col] = min(dist[row][col], 1 + availAtCol[col].back()[1]);
                    }
                    if(!availAtCurrentRow.empty() && availAtCurrentRow.back()[0] <= col + grid[row][col]){
                        dist[row][col] = min(dist[row][col], 1 + availAtCurrentRow.back()[1]);
                    }

                    while(!availAtCol[col].empty() && dist[row][col] <= availAtCol[col].back()[1]){
                        availAtCol[col].pop_back();
                    }

                    while(!availAtCurrentRow.empty() && dist[row][col] <= availAtCurrentRow.back()[1]){
                        availAtCurrentRow.pop_back();
                    }

                    availAtCol[col].push_back({row, dist[row][col]});
                    availAtCurrentRow.push_back({col, dist[row][col]});
                }
            }
        }

        if(dist[0][0] == INF){
            return -1;
        }
        return dist[0][0];
    }
};