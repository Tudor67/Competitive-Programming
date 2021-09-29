class Solution {
private:
    const int INF = 1e9;
    
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
    
    set<int> getMaskSet3(const vector<vector<int>>& BOARD, bool isTransposed = false){
        const int N = BOARD.size();
        set<int> maskSet;
        for(int i = 0; i < N; ++i){
            int mask = 0;
            for(int j = 0; j < N; ++j){
                if(isTransposed){
                    mask = 2 * mask + BOARD[j][i];
                }else{
                    mask = 2 * mask + BOARD[i][j];
                }
            }
            maskSet.insert(mask);
            if((int)maskSet.size() >= 3){
                break;
            }
        }
        return maskSet;
    }
    
    int getMinMoves(set<int>& maskSet, int mask0, int mask1, int boardZeros, int boardOnes, const int& N){
        int minMoves = INF;
        for(int mask: maskSet){
            int maskOnes = __builtin_popcount((unsigned int)mask);
            int maskZeros = N - maskOnes;
            int moves = INF;
            int movesToMask0 = __builtin_popcount((unsigned int)(mask ^ mask0)) / 2;
            int movesToMask1 = __builtin_popcount((unsigned int)(mask ^ mask1)) / 2;
            if(boardZeros < boardOnes){
                if(maskZeros < maskOnes){
                    moves = movesToMask1;
                }
            }else if(boardZeros > boardOnes){
                if(maskZeros > maskOnes){
                    moves = movesToMask0;
                }
            }else{
                moves = min(movesToMask0, movesToMask1);
            }
            minMoves = min(minMoves, moves);
        }
        return minMoves;
    }
    
public:
    int movesToChessboard(vector<vector<int>>& board) {
        const int N = board.size();
        
        // Step 1: check if board is a chessboard
        if(isChessBoard(board)){
            return 0;
        }
        
        // Step 2: sanity check
        set<int> rowMasks = getMaskSet3(board, false);
        set<int> colMasks = getMaskSet3(board, true);
        
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
        int boardZeros = 0;
        int boardOnes = 0;
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < N; ++col){
                boardZeros += (board[row][col] == 0);
                boardOnes += (board[row][col] == 1);
            }
        }
        
        int mask0 = 0;
        int mask1 = 0;
        for(int bit = 0; bit < N; ++bit){
            mask0 |= (bit % 2) << bit;
            mask1 |= ((bit + 1) % 2) << bit;
        }
        
        return getMinMoves(rowMasks, mask0, mask1, boardZeros, boardOnes, N) + 
               getMinMoves(colMasks, mask0, mask1, boardZeros, boardOnes, N);
    }
};