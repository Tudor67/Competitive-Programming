class Solution {
private:
    const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    void bfs(vector<vector<int>>& matrix, const vector<pair<int, int>>& SOURCES, vector<vector<bool>>& vis){
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        
        for(int row = 0; row < ROWS; ++row){
            fill(vis[row].begin(), vis[row].end(), false);
        }
        
        queue<pair<int, int>> q;
        for(const pair<int, int>& P: SOURCES){
            q.push(P);
            vis[P.first][P.second] = true;
        }
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                bool isInside = (0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS);
                if(isInside && !vis[nextRow][nextCol] && matrix[row][col] <= matrix[nextRow][nextCol]){
                    q.push({nextRow, nextCol});
                    vis[nextRow][nextCol] = true;
                }
            }
        }
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.empty()){
            return {};
        }
        
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        
        vector<pair<int, int>> sourcesFromPacific;
        vector<pair<int, int>> sourcesFromAtlantic;
        vector<vector<bool>> isConnectedToPacific(ROWS, vector<bool>(COLS));
        vector<vector<bool>> isConnectedToAtlantic(ROWS, vector<bool>(COLS));
        
        for(int row = 0; row < ROWS; ++row){
            sourcesFromPacific.emplace_back(row, 0);
            sourcesFromAtlantic.emplace_back(row, COLS - 1);
        }
        
        for(int col = 0; col < COLS; ++col){
            sourcesFromPacific.emplace_back(0, col);
            sourcesFromAtlantic.emplace_back(ROWS - 1, col);
        }    
        
        bfs(matrix, sourcesFromPacific, isConnectedToPacific);
        bfs(matrix, sourcesFromAtlantic, isConnectedToAtlantic);
        
        vector<vector<int>> answer;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(isConnectedToPacific[row][col] && isConnectedToAtlantic[row][col]){
                    answer.push_back({row, col});
                }
            }
        }
        
        return answer;
    }
};