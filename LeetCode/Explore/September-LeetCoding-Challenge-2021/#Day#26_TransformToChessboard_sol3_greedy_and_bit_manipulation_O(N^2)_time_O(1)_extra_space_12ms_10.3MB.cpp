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
        set<int> colMasks;
        for(int row = 0; row < N; ++row){
            int colMask = 0;
            for(int col = 0; col < N; ++col){
                colMask = 2 * colMask + board[row][col];
            }
            colMasks.insert(colMask);
            if((int)colMasks.size() >= 3){
                break;
            }
        }
        
        set<int> rowMasks;
        for(int col = 0; col < N; ++col){
            int rowMask = 0;
            for(int row = 0; row < N; ++row){
                rowMask = 2 * rowMask + board[row][col];
            }
            rowMasks.insert(rowMask);
            if((int)rowMasks.size() >= 3){
                break;
            }
        }
        
        if((int)rowMasks.size() != 2 || (int)colMasks.size() != 2){
            return -1;
        }
        
        int firstRowOnes = __builtin_popcount((unsigned int)*rowMasks.begin());
        int firstRowZeros = N - firstRowOnes;
        int secondRowOnes = __builtin_popcount((unsigned int)*rowMasks.rbegin());
        int secondRowZeros = N - secondRowOnes;
        int firstColOnes = __builtin_popcount((unsigned int)*colMasks.begin());
        int firstColZeros = N - firstColOnes;
        int secondColOnes = __builtin_popcount((unsigned int)*colMasks.rbegin());
        int secondColZeros = N - secondColOnes;
        
        if(abs(firstRowOnes - firstRowZeros) > N % 2 || abs(secondRowOnes - secondRowZeros) > N % 2 || 
           abs(firstColOnes - firstColZeros) > N % 2 || abs(secondColOnes - secondColZeros) > N % 2){
            return -1;
        }
        
        // Step 3: compute min moves using a greedy approach:
        //         - fix the value of the starting row and starting column
        //           (depending on the total number of zeros and ones in the board);
        //         - fix the index of the starting row and starting column
        //           (depending on the total number of zeros and ones in the board);
        //         - find bad rows and bad cols;
        //         - count the number of swaps for bad rows (= badRows / 2);
        //         - count the number of swaps for bad cols (= badCols / 2);
        //         - update the answer;
        int zerosCount = 0;
        int onesCount = 0;
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < N; ++col){
                zerosCount += (board[row][col] == 0);
                onesCount += (board[row][col] == 1);
            }
        }
        
        int mask0 = 0;
        int mask1 = 0;
        for(int bit = 0; bit < N; ++bit){
            mask0 |= (bit % 2) << bit;
            mask1 |= ((bit + 1) % 2) << bit;
        }
        
        int minRowMoves = INF;
        for(int rowMask: rowMasks){
            int rowMoves = INF;
            int rowMovesToMask0 = __builtin_popcount((unsigned int)(rowMask ^ mask0)) / 2;
            int rowMovesToMask1 = __builtin_popcount((unsigned int)(rowMask ^ mask1)) / 2;
            if(zerosCount < onesCount){
                if(2 * __builtin_popcount((unsigned int)rowMask) > N){
                    rowMoves = rowMovesToMask1;
                }
            }else if(zerosCount > onesCount){
                if(2 * __builtin_popcount((unsigned int)rowMask) < N){
                    rowMoves = rowMovesToMask0;
                }
            }else{
                rowMoves = min(rowMovesToMask0, rowMovesToMask1);
            }
            minRowMoves = min(minRowMoves, rowMoves);
        }
        
        int minColMoves = INF;
        for(int colMask: colMasks){
            int colMoves = INF;
            int colMovesToMask0 = __builtin_popcount((unsigned int)(colMask ^ mask0)) / 2;
            int colMovesToMask1 = __builtin_popcount((unsigned int)(colMask ^ mask1)) / 2;
            if(zerosCount < onesCount){
                if(2 * __builtin_popcount((unsigned int)colMask) > N){
                    colMoves = colMovesToMask1;
                }
            }else if(zerosCount > onesCount){
                if(2 * __builtin_popcount((unsigned int)colMask) < N){
                    colMoves = colMovesToMask0;
                }
            }else{
                colMoves = min(colMovesToMask0, colMovesToMask1);
            }
            minColMoves = min(minColMoves, colMoves);
        }
        
        return minRowMoves + minColMoves;
    }
};