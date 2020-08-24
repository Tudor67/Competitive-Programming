int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    const int INF = 1e9;
    const int N = grid.size();

    vector<vector<int>> dist(N, vector<int>(N, INF));
    dist[startX][startY] = 0;
    
    queue<pair<int, int>> q;
    q.push({startX, startY});

    while(!q.empty() && dist[goalX][goalY] == INF){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(const pair<int, int>& DIRECTION: DIRECTIONS){
            for(int next_x = x + DIRECTION.first, next_y = y + DIRECTION.second;
                next_x >= 0 && next_x < N && next_y >= 0 && next_y < N && grid[next_x][next_y] == '.';
                next_x += DIRECTION.first, next_y += DIRECTION.second){
                if(dist[next_x][next_y] == INF){
                    dist[next_x][next_y] = 1 + dist[x][y];
                    q.push({next_x, next_y});
                }
            }
        }
    }

    return dist[goalX][goalY];
}