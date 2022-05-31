class Solution {
private:
    int getMaxLen(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& maxLen){
        static const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        
        if(maxLen[row][col] > 0){
            return maxLen[row][col];
        }
        
        maxLen[row][col] = 1;
        for(const pair<int, int>& DIRECTION: DIRECTIONS){
            int nextRow = row + DIRECTION.first;
            int nextCol = col + DIRECTION.second;
            if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                if(matrix[row][col] < matrix[nextRow][nextCol]){
                    maxLen[row][col] = max(maxLen[row][col], 1 + getMaxLen(nextRow, nextCol, matrix, maxLen));
                }
            }
        }
        
        return maxLen[row][col];
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        
        int res = 0;
        vector<vector<int>> maxLen(ROWS, vector<int>(COLS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                maxLen[row][col] = getMaxLen(row, col, matrix, maxLen);
                res = max(res, maxLen[row][col]);
            }
        }
        
        return res;
    }
};