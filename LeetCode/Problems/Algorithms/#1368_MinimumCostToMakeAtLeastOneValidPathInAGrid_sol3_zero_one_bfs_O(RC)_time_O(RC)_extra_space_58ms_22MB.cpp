class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        const vector<pair<int, int>> DIRECTIONS = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        const int INF = 1e8;
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        vector<vector<int>> dist(ROWS, vector<int>(COLS, INF));
        vector<vector<bool>> processed(ROWS, vector<bool>(COLS, false));
        deque<pair<int, int>> dq;
        dq.emplace_front(0, 0);
        dist[0][0] = 0;
        while(!dq.empty()){
            int row = dq.front().first;
            int col = dq.front().second;
            dq.pop_front();
            
            if(row == ROWS - 1 && col == COLS - 1){
                return dist[ROWS - 1][COLS - 1];
            }
            
            if(processed[row][col]){
                continue;
            }
            processed[row][col] = true;
            
            for(int dirIdx = 0; dirIdx < (int)DIRECTIONS.size(); ++dirIdx){
                int weight = (dirIdx != grid[row][col] - 1);
                int nextRow = row + DIRECTIONS[dirIdx].first;
                int nextCol = col + DIRECTIONS[dirIdx].second;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                    if(dist[row][col] + weight < dist[nextRow][nextCol]){
                        dist[nextRow][nextCol] = dist[row][col] + weight;
                        if(weight == 0){
                            dq.emplace_front(nextRow, nextCol);
                        }else{
                            dq.emplace_back(nextRow, nextCol);
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};