class Solution {
private:
    enum CellSide { TOP, BOTTOM, LEFT, RIGHT };
    
    int getNode(int row, int col, CellSide cellSide, const int& ROWS, const int& COLS){
        if(cellSide == CellSide::TOP){
            return row * COLS + col;
        }else if(cellSide == CellSide::BOTTOM){
            return (row + 1) * COLS + col;
        }else if(cellSide == CellSide::LEFT){
            return (ROWS + 1) * COLS + row * (COLS + 1) + col;
        }else if(cellSide == CellSide::RIGHT){
            return (ROWS + 1) * COLS + row * (COLS + 1) + col + 1;
        }
        return -1;
    }
    
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int N = getNode(ROWS - 1, COLS - 1, CellSide::RIGHT, ROWS, COLS) + 1;
        const int INF = 1e9;
        
        // Graph
        vector<int> nextNodeFrom(N, INF);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == -1){
                    int x1 = getNode(row, col, CellSide::TOP, ROWS, COLS);
                    int y1 = getNode(row, col, CellSide::LEFT, ROWS, COLS);
                    nextNodeFrom[x1] = y1;
                    int x2 = getNode(row, col, CellSide::RIGHT, ROWS, COLS);
                    int y2 = getNode(row, col, CellSide::BOTTOM, ROWS, COLS);
                    nextNodeFrom[x2] = y2;
                }else if(grid[row][col] == 1){
                    int x1 = getNode(row, col, CellSide::TOP, ROWS, COLS);
                    int y1 = getNode(row, col, CellSide::RIGHT, ROWS, COLS);
                    nextNodeFrom[x1] = y1;
                    int x2 = getNode(row, col, CellSide::LEFT, ROWS, COLS);
                    int y2 = getNode(row, col, CellSide::BOTTOM, ROWS, COLS);
                    nextNodeFrom[x2] = y2;
                }
            }
        }
        
        // bfs
        queue<int> q;
        vector<int> ballIndex(N, INF);
        for(int col = 0; col < COLS; ++col){
            int node = getNode(0, col, CellSide::TOP, ROWS, COLS);
            q.push(node);
            ballIndex[node] = col;
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            if(nextNodeFrom[node] != INF){
                int nextNode = nextNodeFrom[node];
                if(ballIndex[nextNode] == INF){
                    ballIndex[nextNode] = ballIndex[node];
                    q.push(nextNode);
                }else{
                    ballIndex[nextNode] = INF;
                }
            }
        }
        
        // answer
        vector<int> answer(COLS, -1);
        for(int col = 0; col < COLS; ++col){
            int node = getNode(ROWS - 1, col, CellSide::BOTTOM, ROWS, COLS);
            if(ballIndex[node] != INF){
                answer[ballIndex[node]] = col;
            }
        }
        
        return answer;
    }
};