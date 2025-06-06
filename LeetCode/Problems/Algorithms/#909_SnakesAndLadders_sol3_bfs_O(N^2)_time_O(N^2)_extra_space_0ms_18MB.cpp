class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        const int ROWS = board.size();
        const int COLS = board[0].size();
        const int INF = 1e9;

        int currentIndex = 1;
        vector<int> rowOf(ROWS * COLS + 1);
        vector<int> colOf(ROWS * COLS + 1);
        
        for(int row = ROWS - 1; row >= 0; --row){
            if(row % 2 == (ROWS - 1) % 2){
                for(int col = 0; col < COLS; ++col){
                    rowOf[currentIndex] = row;
                    colOf[currentIndex] = col;
                    currentIndex += 1;
                }
            }else{
                for(int col = COLS - 1; col >= 0; --col){
                    rowOf[currentIndex] = row;
                    colOf[currentIndex] = col;
                    currentIndex += 1;
                }
            }
        }

        vector<int> minDist(ROWS * COLS + 1, INF);
        minDist[1] = 0;

        queue<int> q;
        q.push(1);

        while(!q.empty() && minDist[ROWS * COLS] == INF){
            int index = q.front();
            q.pop();

            for(int nextIndex = index + 1; nextIndex <= min(index + 6, ROWS * COLS); ++nextIndex){
                if(board[rowOf[nextIndex]][colOf[nextIndex]] == -1){
                    if(minDist[nextIndex] == INF){
                        minDist[nextIndex] = minDist[index] + 1;
                        q.push(nextIndex);
                    }
                }else{
                    int nextNextIndex = board[rowOf[nextIndex]][colOf[nextIndex]];
                    if(minDist[nextNextIndex] == INF){
                        minDist[nextNextIndex] = minDist[index] + 1;
                        q.push(nextNextIndex);
                    }
                }
            }
        }

        if(minDist[ROWS * COLS] == INF){
            minDist[ROWS * COLS] = -1;
        }

        return minDist[ROWS * COLS];
    }
};