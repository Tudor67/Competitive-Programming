class Solution {
private:
    int flip(int matVal, int cellIdx, const int& ROWS, const int& COLS){
        static const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        int row = cellIdx / COLS;
        int col = cellIdx % COLS;
        int matNextVal = matVal ^ (1 << cellIdx);
        for(const pair<int, int>& DIRECTION: DIRECTIONS){
            int nextRow = row + DIRECTION.first;
            int nextCol = col + DIRECTION.second;
            if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                int cellNextIdx = nextRow * COLS + nextCol;
                matNextVal ^= (1 << cellNextIdx);
            }
        }
        return matNextVal;
    }
    
public:
    int minFlips(vector<vector<int>>& mat) {
        const int ROWS = mat.size();
        const int COLS = mat[0].size();
        const int N = ROWS * COLS;
        const int FULL_MASK = (1 << N) - 1;
        const int INF = 1e8;
        
        int matVal = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                matVal = 2 * matVal + mat[row][col];
            }
        }
        
        int minFlips = INF;
        for(int mask = 0; mask <= FULL_MASK; ++mask){
            int matNextVal = matVal;
            int flips = 0;
            for(int cellIdx = 0; cellIdx < N; ++cellIdx){
                if((mask >> cellIdx) & 1){
                    matNextVal = flip(matNextVal, cellIdx, ROWS, COLS);
                    flips += 1;
                }
            }
            if(matNextVal == 0 && flips < minFlips){
                minFlips = flips;
            }
        }
        
        if(minFlips == INF){
            minFlips = -1;
        }
        
        return minFlips;
    }
};