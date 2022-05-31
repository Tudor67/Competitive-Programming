class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        static const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        
        vector<vector<int>> inDegree(ROWS, vector<int>(COLS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                for(const pair<int, int>& DIRECTION: DIRECTIONS){
                    int nextRow = row + DIRECTION.first;
                    int nextCol = col + DIRECTION.second;
                    if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                        if(matrix[row][col] < matrix[nextRow][nextCol]){
                            inDegree[nextRow][nextCol] += 1;
                        }
                    }
                }
            }
        }
        
        queue<pair<int, int>> q;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(inDegree[row][col] == 0){
                    q.emplace(row, col);
                }
            }
        }
        
        int maxLen = 0;
        while(!q.empty()){
            maxLen += 1;
            for(int i = q.size(); i >= 1; --i){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
                for(const pair<int, int>& DIRECTION: DIRECTIONS){
                    int nextRow = row + DIRECTION.first;
                    int nextCol = col + DIRECTION.second;
                    if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                        if(matrix[row][col] < matrix[nextRow][nextCol]){
                            inDegree[nextRow][nextCol] -= 1;
                            if(inDegree[nextRow][nextCol] == 0){
                                q.emplace(nextRow, nextCol);
                            }
                        }
                    }
                }
            }
        }
        
        return maxLen;
    }
};