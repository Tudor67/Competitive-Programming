class DSU{
private:
    vector<int> parent;
    vector<int> rank;
    
public:
    DSU(const int& N){
        rank.resize(N + 1);
        parent.resize(N + 1);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x){
        if(x != parent[x]){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void join(int x, int y){
        int xRoot = find(x);
        int yRoot = find(y);
        if(xRoot != yRoot){
            if(rank[xRoot] <= rank[yRoot]){
                parent[xRoot] = yRoot;
                rank[yRoot] += (int)(rank[xRoot] == rank[yRoot]);
            }else{
                parent[yRoot] = xRoot;
            }
        }
    }
};

class Solution {
private:
    int getIdx(int row, int col, const int& COLS){
        return row * COLS + col;
    }
    
public:
    void solve(vector<vector<char>>& board) {
        static const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        const int ROWS = board.size();
        const int COLS = board[0].size();
        
        DSU dsu(ROWS * COLS);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(board[row][col] == 'O'){
                    for(const pair<int, int>& DIRECTION: DIRECTIONS){
                        int nextRow = row + DIRECTION.first;
                        int nextCol = col + DIRECTION.second;
                        if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS && 
                           board[nextRow][nextCol] == 'O'){
                            dsu.join(getIdx(row, col, COLS), getIdx(nextRow, nextCol, COLS));
                        }
                    }
                }
            }
        }
        
        vector<bool> isValid(ROWS * COLS, true);
        for(int row = 0; row < ROWS; ++row){
            isValid[dsu.find(getIdx(row, 0, COLS))] = false;
            isValid[dsu.find(getIdx(row, COLS - 1, COLS))] = false;
        }
        
        for(int col = 0; col < COLS; ++col){
            isValid[dsu.find(getIdx(0, col, COLS))] = false;
            isValid[dsu.find(getIdx(ROWS - 1, col, COLS))] = false;
        }
        
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(isValid[dsu.find(getIdx(row, col, COLS))]){
                    board[row][col] = 'X';
                }
            }
        }
    }
};