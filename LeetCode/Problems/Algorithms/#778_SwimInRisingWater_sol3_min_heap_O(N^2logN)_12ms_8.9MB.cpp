class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        const int N = grid.size();
        
        using T3 = tuple<int, int, int>;
        priority_queue<T3, vector<T3>, greater<T3>> minHeap;
        vector<vector<bool>> vis(N, vector<bool>(N, false));
        
        int answer = max(grid[0][0], grid[N - 1][N - 1]);
        minHeap.push({grid[0][0], 0, 0});
        vis[0][0] = true;
        while(!vis[N - 1][N - 1]){
            int currentVal, currentRow, currentCol;
            tie(currentVal, currentRow, currentCol) = minHeap.top();
            minHeap.pop();
            
            answer = max(currentVal, answer);
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = currentRow + DIRECTION.first;
                int nextCol = currentCol + DIRECTION.second;
                if(0 <= nextRow && nextRow < N && 0 <= nextCol && nextCol < N && !vis[nextRow][nextCol]){
                    minHeap.push({grid[nextRow][nextCol], nextRow, nextCol});
                    vis[nextRow][nextCol] = true;
                }
            }
        }
        
        return answer;
    }
};