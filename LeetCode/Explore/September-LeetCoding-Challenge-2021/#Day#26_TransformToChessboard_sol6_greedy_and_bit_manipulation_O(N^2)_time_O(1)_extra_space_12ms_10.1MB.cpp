class Solution {
private:
    const int INF = 1e9;
    
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
        const int FULL_MASK = (1 << N) - 1;
        
        // Sanity check
        int rowMask = 0;
        int colMask = 0;
        for(int i = 0; i < N; ++i){
            rowMask = rowMask * 2 + board[0][i];
            colMask = colMask * 2 + board[i][0];
        }
        
        set<int> rowMasks = {rowMask, rowMask ^ FULL_MASK};
        set<int> colMasks = {colMask, colMask ^ FULL_MASK};
        
        for(int i = 0; i < N; ++i){
            int rowMask = 0;
            int colMask = 0;
            for(int j = 0; j < N; ++j){
                rowMask = rowMask * 2 + board[i][j];
                colMask = colMask * 2 + board[j][i];
            }
            if(!rowMasks.count(rowMask) || !colMasks.count(colMask)){
                return -1;
            }
        }
        
        // Compute min moves using a greedy approach
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