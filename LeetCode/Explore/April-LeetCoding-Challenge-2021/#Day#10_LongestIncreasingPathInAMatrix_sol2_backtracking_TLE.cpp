class Solution {
private:
    const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    int solve(int row, int col, vector<vector<int>>& matrix, const int& ROWS, const int& COLS){
        int maxLength = 0;
        for(const pair<int, int>& DIRECTION: DIRECTIONS){
            int nextRow = row + DIRECTION.first;
            int nextCol = col + DIRECTION.second;
            if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS && matrix[nextRow][nextCol] < matrix[row][col]){
                maxLength = max(solve(nextRow, nextCol, matrix, ROWS, COLS), maxLength);
            }
        }
        return 1 + maxLength;
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        int answer = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                answer = max(solve(row, col, matrix, ROWS, COLS), answer);
            }
        }
        return answer;
    }
};