int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
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

        for(int next_x = x + 1; next_x < N && grid[next_x][y] == '.'; ++next_x){
            if(dist[next_x][y] == INF){
                dist[next_x][y] = 1 + dist[x][y];
                q.push({next_x, y});
            }
        }

        for(int next_x = x - 1; next_x >= 0 && grid[next_x][y] == '.'; --next_x){
            if(dist[next_x][y] == INF){
                dist[next_x][y] = 1 + dist[x][y];
                q.push({next_x, y});
            }
        }

        for(int next_y = y + 1; next_y < N && grid[x][next_y] == '.'; ++next_y){
            if(dist[x][next_y] == INF){
                dist[x][next_y] = 1 + dist[x][y];
                q.push({x, next_y});
            }
        }

        for(int next_y = y - 1; next_y >= 0 && grid[x][next_y] == '.'; --next_y){
            if(dist[x][next_y] == INF){
                dist[x][next_y] = 1 + dist[x][y];
                q.push({x, next_y});
            }
        }
    }

    return dist[goalX][goalY];
}