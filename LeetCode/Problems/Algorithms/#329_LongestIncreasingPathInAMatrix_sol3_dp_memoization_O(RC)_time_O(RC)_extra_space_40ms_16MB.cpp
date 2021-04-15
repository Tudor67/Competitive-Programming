class Solution {
private:
    const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    int solve(vector<vector<int>>& memo, int row, int col, vector<vector<int>>& matrix, const int& ROWS, const int& COLS){
        if(memo[row][col] == 0){
            int maxLength = 0;
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS && matrix[nextRow][nextCol] < matrix[row][col]){
                    maxLength = max(solve(memo, nextRow, nextCol, matrix, ROWS, COLS), maxLength);
                }
            }
            memo[row][col] = 1 + maxLength;
        }
        return memo[row][col];
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        vector<vector<int>> memo(ROWS, vector<int>(COLS, 0));
        int answer = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                answer = max(solve(memo, row, col, matrix, ROWS, COLS), answer);
            }
        }
        return answer;
    }
};