class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int INF = 1e9;
        
        vector<set<int>> availableAtRow(ROWS);
        vector<set<int>> availableAtCol(COLS);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                availableAtRow[row].insert(col);
                availableAtCol[col].insert(row);
            }
        }

        vector<vector<int>> dist(ROWS, vector<int>(COLS, INF));
        queue<pair<int, int>> q;
        q.push({0, 0});
        dist[0][0] = 1;
        
        while(!q.empty() && dist[ROWS - 1][COLS - 1] == INF){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            int maxRow = grid[row][col] + row;
            int maxCol = grid[row][col] + col;
            
            set<int>::iterator rowItStart = availableAtRow[row].lower_bound(col);
            set<int>::iterator rowItEnd = availableAtRow[row].upper_bound(maxCol);
            for(set<int>::iterator it = rowItStart; it != rowItEnd; it = next(it)){
                int nextRow = row;
                int nextCol = *it;
                if(dist[row][col] + 1 < dist[nextRow][nextCol]){
                    dist[nextRow][nextCol] = dist[row][col] + 1;
                    q.push({nextRow, nextCol});
                }
            }
            
            set<int>::iterator colItStart = availableAtCol[col].lower_bound(row);
            set<int>::iterator colItEnd = availableAtCol[col].upper_bound(maxRow);
            for(set<int>::iterator it = colItStart; it != colItEnd; it = next(it)){
                int nextRow = *it;
                int nextCol = col;
                if(dist[row][col] + 1 < dist[nextRow][nextCol]){
                    dist[nextRow][nextCol] = dist[row][col] + 1;
                    q.push({nextRow, nextCol});
                }
            }
            
            availableAtRow[row].erase(rowItStart, rowItEnd);
            availableAtCol[col].erase(colItStart, colItEnd);
        }
        
        if(dist[ROWS - 1][COLS - 1] == INF){
            return -1;
        }
        return dist[ROWS - 1][COLS - 1];
    }
};