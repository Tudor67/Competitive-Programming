class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int INF = 1e9;

        using PII = pair<int, int>;
        using MinHeap = priority_queue<PII, vector<PII>, greater<PII>>;
        vector<MinHeap> availAtCol(COLS);
        MinHeap availAtCurrentRow;
        for(int col = 0; col < COLS; ++col){
            availAtCol[col].push({INF, ROWS - 1});
        }

        vector<vector<int>> dist(ROWS, vector<int>(COLS, INF));
        dist[0][0] = 1;

        for(int row = 0; row < ROWS; ++row){
            while(!availAtCurrentRow.empty()){
                availAtCurrentRow.pop();
            }
            availAtCurrentRow.push({INF, COLS - 1});

            for(int col = 0; col < COLS; ++col){
                while(availAtCurrentRow.top().second < col){
                    availAtCurrentRow.pop();
                }
                while(availAtCol[col].top().second < row){
                    availAtCol[col].pop();
                }
                
                dist[row][col] = min(dist[row][col], 1 + min(availAtCurrentRow.top().first, availAtCol[col].top().first));

                availAtCurrentRow.push({dist[row][col], grid[row][col] + col});
                availAtCol[col].push({dist[row][col], grid[row][col] + row});
            }
        }

        if(dist[ROWS - 1][COLS - 1] == INF){
            return -1;
        }
        return dist[ROWS - 1][COLS - 1];
    }
};