class Solution {
private:    
    bool isValid(vector<vector<int>>& heights, vector<vector<bool>>& vis, const int& MAX_EFFORT){
        const vector<pair<int, int>> DIRECTIONS = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        const int ROWS = heights.size();
        const int COLS = heights[0].size();
        
        queue<pair<int, int>> q;
        for(int row = 0; row < ROWS; ++row){
            fill(vis[row].begin(), vis[row].end(), false);
        }
        
        q.push({0, 0});
        vis[0][0] = true;
        while(!q.empty() && !vis[ROWS - 1][COLS - 1]){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                bool isInside = (0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS);
                if(isInside && !vis[nextRow][nextCol]){
                    int effort = abs(heights[row][col] - heights[nextRow][nextCol]);
                    if(effort <= MAX_EFFORT){
                        q.push({nextRow, nextCol});
                        vis[nextRow][nextCol] = true;
                    }
                }
            }
        }
        
        return vis[ROWS - 1][COLS - 1];
    }
    
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        const int MAX_HEIGHT = 1e6;
        const int ROWS = heights.size();
        const int COLS = heights[0].size();
        vector<vector<bool>> vis(ROWS, vector<bool>(COLS));
        int l = 0;
        int r = MAX_HEIGHT;
        while(l != r){
            int mid = (l + r) / 2;
            if(isValid(heights, vis, mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return r;
    }
};