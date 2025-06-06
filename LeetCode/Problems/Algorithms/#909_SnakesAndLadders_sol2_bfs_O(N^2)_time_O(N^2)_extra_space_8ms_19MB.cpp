class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        const int ROWS = board.size();
        const int COLS = board[0].size();
        const int INF = 1e9;

        vector<vector<int>> indices(ROWS, vector<int>(COLS));
        vector<int> rowOf(ROWS * COLS + 1);
        vector<int> colOf(ROWS * COLS + 1);
        int currIndex = 1;
        for(int row = ROWS - 1; row >= 0; --row){
            for(int col = 0; col < COLS; ++col){
                indices[row][col] = currIndex;
                currIndex += 1;
            }
            if((ROWS - 1 - row) % 2 == 1){
                reverse(indices[row].begin(), indices[row].end());
            }
            for(int col = 0; col < COLS; ++col){
                rowOf[indices[row][col]] = row;
                colOf[indices[row][col]] = col;
            }
        }
        
        vector<vector<int>> minDist(ROWS, vector<int>(COLS, INF));
        minDist[ROWS - 1][0] = 0;

        queue<pair<int, int>> q;
        q.push({ROWS - 1, 0});

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int firstNextIndex = indices[row][col] + 1;
            int lastNextIndex = min(indices[row][col] + 6, ROWS * COLS);
            for(int nextIndex = firstNextIndex; nextIndex <= lastNextIndex; ++nextIndex){
                int nextRow = rowOf[nextIndex];
                int nextCol = colOf[nextIndex];
                if(board[nextRow][nextCol] == -1 && minDist[nextRow][nextCol] == INF){
                    minDist[nextRow][nextCol] = minDist[row][col] + 1;
                    q.push({nextRow, nextCol});
                }
                if(board[nextRow][nextCol] != -1){
                    int nextNextIndex = board[nextRow][nextCol];
                    int nextNextRow = rowOf[nextNextIndex];
                    int nextNextCol = colOf[nextNextIndex];
                    if(minDist[nextNextRow][nextNextCol] == INF){
                        minDist[nextNextRow][nextNextCol] = minDist[row][col] + 1;
                        q.push({nextNextRow, nextNextCol});
                    }
                }
            }
        }

        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(minDist[row][col] == INF){
                    minDist[row][col] = -1;
                }
            }
        }

        return minDist[rowOf[ROWS * COLS]][colOf[ROWS * COLS]];
    }
};