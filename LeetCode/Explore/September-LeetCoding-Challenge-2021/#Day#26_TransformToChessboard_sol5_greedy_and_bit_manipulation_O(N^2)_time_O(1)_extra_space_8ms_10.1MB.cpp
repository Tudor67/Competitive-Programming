class Solution {
private:
    const int INF = 1e9;
    
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
    
    int getMinMoves(set<int>& maskSet, int mask0, int mask1){
        int minMoves = INF;
        int mask0Ones = __builtin_popcount((unsigned int)mask0);
        int mask1Ones = __builtin_popcount((unsigned int)mask1);
        for(int mask: maskSet){
            int maskOnes = __builtin_popcount((unsigned int)mask);
            int moves = INF;
            int movesToMask0 = __builtin_popcount((unsigned int)(mask ^ mask0)) / 2;
            int movesToMask1 = __builtin_popcount((unsigned int)(mask ^ mask1)) / 2;
            if(maskOnes == mask0Ones && maskOnes == mask1Ones){
                moves = min(movesToMask0, movesToMask1);
            }else if(maskOnes == mask0Ones){
                moves = movesToMask0;
            }else if(maskOnes == mask1Ones){
                moves = movesToMask1;
            }
            minMoves = min(minMoves, moves);
        }
        return minMoves;
    }
    
public:
    int movesToChessboard(vector<vector<int>>& board) {
        const int N = board.size();
        
        // Step 1: sanity check
        set<int> rowMasks = getMaskSet3(board, false);
        set<int> colMasks = getMaskSet3(board, true);
        
        if((int)rowMasks.size() != 2 || (int)colMasks.size() != 2){
            return -1;
        }
        
        // Step 2: compute min moves using a greedy approach:
        //         - fix the value of the starting row and starting column
        //           (depending on the total number of zeros and ones in the board);
        //         - fix the index of the starting row and starting column
        //           (depending on the total number of zeros and ones in the board);
        //         - find bad rows and bad cols;
        //         - count the number of swaps for bad rows (= badRows / 2);
        //         - count the number of swaps for bad cols (= badCols / 2);
        //         - update the answer;
        int mask0 = 0;
        int mask1 = 0;
        for(int bit = 0; bit < N; ++bit){
            mask0 |= (bit % 2) << bit;
            mask1 |= ((bit + 1) % 2) << bit;
        }
        
        int minMoves = getMinMoves(rowMasks, mask0, mask1) + 
                       getMinMoves(colMasks, mask0, mask1);
        
        if(minMoves >= INF){
            minMoves = -1;
        }
        
        return minMoves;
    }
};