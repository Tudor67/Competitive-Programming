class Solution {
private:
    bool isChessBoard(const vector<vector<int>>& BOARD){
        const int N = BOARD.size();
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < N; ++col){
                if(row >= 1 && BOARD[row - 1][col] == BOARD[row][col]){
                    return false;
                }
                if(col >= 1 && BOARD[row][col - 1] == BOARD[row][col]){
                    return false;
                }
            }
        }
        return true;
    }
    
public:
    int movesToChessboard(vector<vector<int>>& board) {
        const int N = board.size();
        const int INF = 1e9;
        
        // Compute min moves using a greedy approach:
        // - fix the value of the starting row and starting column
        // - find bad rows and bad cols;
        // - swap bad rows;
        // - swap bad cols;
        // - if the final board is a chessboard then update the answer;
        vector<pair<int, int>> rowColStartValues = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
        
        int minMoves = INF;
        for(const pair<int, int>& ROW_COL_START_VAL: rowColStartValues){
            const int ROW_START_VAL = ROW_COL_START_VAL.first;
            const int COL_START_VAL = ROW_COL_START_VAL.second;
            
            vector<vector<int>> badRows(2);
            for(int row = 0; row < N; ++row){
                int expectedVal = (row + ROW_START_VAL) % 2;
                if(board[row][0] != expectedVal){
                    badRows[expectedVal].push_back(row);
                }
            }
            
            vector<vector<int>> badCols(2);
            for(int col = 0; col < N; ++col){
                int expectedVal = (col + COL_START_VAL) % 2;
                if(board[0][col] != expectedVal){
                    badCols[expectedVal].push_back(col);
                }
            }
            
            int moves = 0;
            vector<vector<int>> b = board;
            while(!badRows[0].empty() && !badRows[1].empty()){
                int row0 = badRows[0].back(); badRows[0].pop_back();
                int row1 = badRows[1].back(); badRows[1].pop_back();
                swap(b[row0], b[row1]);
                moves += 1;
            }
            
            while(!badCols[0].empty() && !badCols[1].empty()){
                int col0 = badCols[0].back(); badCols[0].pop_back();
                int col1 = badCols[1].back(); badCols[1].pop_back();
                for(int row = 0; row < N; ++row){
                    swap(b[row][col0], b[row][col1]);
                }
                moves += 1;
            }
            
            if(isChessBoard(b)){
                minMoves = min(minMoves, moves);
            }
        }
        
        if(minMoves == INF){
            minMoves = -1;
        }
        
        return minMoves;
    }
};