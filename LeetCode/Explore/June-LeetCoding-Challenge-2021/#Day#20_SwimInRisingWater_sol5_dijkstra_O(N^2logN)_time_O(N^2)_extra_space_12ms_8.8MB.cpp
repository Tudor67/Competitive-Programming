class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        static const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        const int N = grid.size();
        const int INF = 1e9;
        
        using Position = pair<int, int>;
        using P = pair<int, Position>;
        priority_queue<P, vector<P>, greater<P>> minHeap;
        vector<vector<int>> minT(N, vector<int>(N, INF));
        
        minHeap.push({grid[0][0], {0, 0}});
        minT[0][0] = grid[0][0];
        while(!minHeap.empty() && minT[N - 1][N - 1] == INF){
            int row = minHeap.top().second.first;
            int col = minHeap.top().second.second;
            minHeap.pop();
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < N && 0 <= nextCol && nextCol < N && minT[nextRow][nextCol] == INF){
                    minT[nextRow][nextCol] = max(minT[row][col], grid[nextRow][nextCol]);
                    minHeap.push({minT[nextRow][nextCol], {nextRow, nextCol}});
                }
            }
        }
        
        return minT[N - 1][N - 1];
    }
};