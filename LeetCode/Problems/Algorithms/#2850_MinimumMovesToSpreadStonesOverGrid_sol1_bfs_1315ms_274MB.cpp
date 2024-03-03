class Solution {
private:
    using Grid = vector<vector<int>>;
    const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

public:
    int minimumMoves(vector<vector<int>>& srcGrid) {
        const int ROWS = srcGrid.size();
        const int COLS = srcGrid[0].size();

        Grid destGrid(ROWS, vector<int>(COLS, 1));
        map<Grid, int> dist;
        queue<Grid> q;
        dist[srcGrid] = 0;
        q.push(srcGrid);

        while(!dist.count(destGrid)){
            Grid grid = q.front();
            q.pop();

            int currentDist = dist[grid];

            for(int row = 0; row < ROWS; ++row){
                for(int col = 0; col < COLS; ++col){
                    if(grid[row][col] <= 1){
                        continue;
                    }
                    for(const pair<int, int>& DIRECTION: DIRECTIONS){
                        int nextRow = row + DIRECTION.first;
                        int nextCol = col + DIRECTION.second;
                        if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                            grid[row][col] -= 1;
                            grid[nextRow][nextCol] += 1;
                            if(!dist.count(grid)){
                                dist[grid] = currentDist + 1;
                                q.push(grid);
                            }
                            grid[row][col] += 1;
                            grid[nextRow][nextCol] -= 1;
                        }
                    }
                }
            }
        }

        return dist[destGrid];
    }
};