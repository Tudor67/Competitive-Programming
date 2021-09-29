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
        
        // Step 1: check if board is a chessboard
        if(isChessBoard(board)){
            return 0;
        }
        
        // Step 2: sanity check
        vector<vector<int>> rowCount(N, vector<int>(2, 0));
        vector<vector<int>> colCount(N, vector<int>(2, 0));
        int zerosCount = 0;
        int onesCount = 0;
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < N; ++col){
                rowCount[row][board[row][col]] += 1;
                colCount[col][board[row][col]] += 1;
                zerosCount += (board[row][col] == 0);
                onesCount += (board[row][col] == 1);
            }
        }
        
        for(int i = 0; i < N; ++i){
            if(abs(rowCount[i][0] - rowCount[i][1]) > (N % 2)){
                return -1;
            }
            if(abs(colCount[i][0] - colCount[i][1]) > (N % 2)){
                return -1;
            }
        }
        
        // Step 3: compute min moves using a greedy approach:
        //         - fix the value of the starting row and starting column
        //           (depending on the total number of zeros and ones in the board);
        //         - fix the index of the starting row and starting column
        //           (depending on the total number of zeros and ones in the board);
        //         - find bad rows and bad cols;
        //         - swap bad rows;
        //         - swap bad cols;
        //         - if the final board is a chessboard then update the answer;
        vector<pair<int, int>> rowColStartValues = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
        int rowStartIdx = 0;
        int colStartIdx = 0;
        if(zerosCount < onesCount){
            rowColStartValues = {{1, 1}};
            for(int i = 0; i < N; ++i){
                if(rowCount[i][1] > rowCount[rowStartIdx][1]){
                    rowStartIdx = i;
                }
                if(colCount[i][1] > colCount[colStartIdx][1]){
                    colStartIdx = i;
                }
            }
        }else if(zerosCount > onesCount){
            rowColStartValues = {{0, 0}};
            for(int i = 0; i < N; ++i){
                if(rowCount[i][0] > rowCount[rowStartIdx][0]){
                    rowStartIdx = i;
                }
                if(colCount[i][0] > colCount[colStartIdx][0]){
                    colStartIdx = i;
                }
            }
        }
        
        int minMoves = INF;
        for(const pair<int, int>& ROW_COL_START_VAL: rowColStartValues){
            const int ROW_START_VAL = ROW_COL_START_VAL.first;
            const int COL_START_VAL = ROW_COL_START_VAL.second;
            
            vector<vector<int>> badRows(2);
            for(int row = 0; row < N; ++row){
                int expectedVal = (row + ROW_START_VAL) % 2;
                if(board[row][colStartIdx] != expectedVal){
                    badRows[expectedVal].push_back(row);
                }
            }
            
            vector<vector<int>> badCols(2);
            for(int col = 0; col < N; ++col){
                int expectedVal = (col + COL_START_VAL) % 2;
                if(board[rowStartIdx][col] != expectedVal){
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