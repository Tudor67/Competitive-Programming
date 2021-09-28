class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        
        vector<int> spiralValues;
        vector<vector<bool>> vis(ROWS, vector<bool>(COLS, false));
        
        int y = 0, yDirection = 0;
        int x = 0, xDirection = 1;
        while(spiralValues.size() < ROWS * COLS){
            spiralValues.push_back(matrix[y][x]);
            vis[y][x] = true;
            int nextY = y + yDirection;
            int nextX = x + xDirection;
            if(nextY < 0 || ROWS <= nextY || nextX < 0 || COLS <= nextX || vis[nextY][nextX]){
                swap(xDirection, yDirection);
                xDirection = -xDirection;
            }
            y += yDirection;
            x += xDirection;
        }
        
        return spiralValues;
    }
};