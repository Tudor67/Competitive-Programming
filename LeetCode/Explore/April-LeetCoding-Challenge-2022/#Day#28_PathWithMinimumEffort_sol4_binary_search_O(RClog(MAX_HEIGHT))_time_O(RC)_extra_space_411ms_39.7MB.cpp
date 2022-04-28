class Solution {
private:
    bool isPossible(vector<vector<int>>& heights, vector<vector<bool>>& vis, const int& MAX_DIFF){
        static const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        const int ROWS = heights.size();
        const int COLS = heights[0].size();
        
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                vis[row][col] = false;
            }
        }
        
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        vis[0][0] = true;
        while(!q.empty() && !vis[ROWS - 1][COLS - 1]){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS && !vis[nextRow][nextCol]){
                    int diff = abs(heights[row][col] - heights[nextRow][nextCol]);
                    if(diff <= MAX_DIFF){
                        vis[nextRow][nextCol] = true;
                        q.emplace(nextRow, nextCol);
                    }
                }
            }
        }
        
        return vis[ROWS - 1][COLS - 1];
    }
    
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        const int ROWS = heights.size();
        const int COLS = heights[0].size();
        
        int minHeight = heights[0][0];
        int maxHeight = heights[0][0];
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                minHeight = min(minHeight, heights[row][col]);
                maxHeight = max(maxHeight, heights[row][col]);
            }
        }
        
        int l = 0;
        int r = maxHeight - minHeight;
        vector<vector<bool>> vis(ROWS, vector<bool>(COLS));
        while(l != r){
            int mid = (l + r) / 2;
            if(isPossible(heights, vis, mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        
        return r;
    }
};