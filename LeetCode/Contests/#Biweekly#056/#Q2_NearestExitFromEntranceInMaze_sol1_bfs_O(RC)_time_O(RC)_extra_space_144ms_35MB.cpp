class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        static const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        static const int INF = 1e8;
        const int ROWS = maze.size();
        const int COLS = maze[0].size();
        
        vector<vector<int>> dist(ROWS, vector<int>(COLS, INF));
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        dist[entrance[0]][entrance[1]] = 0;
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS &&
                   maze[nextRow][nextCol] == '.' && dist[row][col] + 1 < dist[nextRow][nextCol]){
                    q.push({nextRow, nextCol});
                    dist[nextRow][nextCol] = dist[row][col] + 1;
                }
            }
        }
        
        int answer = INF;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++ col){
                if(row == 0 || row == ROWS - 1 || col == 0 || col == COLS - 1){
                    if(row != entrance[0] || col != entrance[1]){
                        answer = min(answer, dist[row][col]);
                    }
                }
            }
        }
        
        if(answer == INF){
            answer = -1;
        }
        
        return answer;
    }
};