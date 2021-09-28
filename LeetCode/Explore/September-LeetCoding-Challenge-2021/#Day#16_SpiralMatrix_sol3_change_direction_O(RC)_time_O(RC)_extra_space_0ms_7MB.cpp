class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        static const vector<pair<int, int>> DIRECTIONS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        
        vector<int> spiralValues;
        vector<vector<bool>> vis(ROWS, vector<bool>(COLS, false));
        
        int y = 0;
        int x = 0;
        int directionIdx = 0;
        while(spiralValues.size() < ROWS * COLS){
            spiralValues.push_back(matrix[y][x]);
            vis[y][x] = true;
            int nextY = y + DIRECTIONS[directionIdx].first;
            int nextX = x + DIRECTIONS[directionIdx].second;
            if(nextY < 0 || ROWS <= nextY || nextX < 0 || COLS <= nextX || vis[nextY][nextX]){
                directionIdx += 1;
                directionIdx %= 4;
            }
            y += DIRECTIONS[directionIdx].first;
            x += DIRECTIONS[directionIdx].second;
        }
        
        return spiralValues;
    }
};