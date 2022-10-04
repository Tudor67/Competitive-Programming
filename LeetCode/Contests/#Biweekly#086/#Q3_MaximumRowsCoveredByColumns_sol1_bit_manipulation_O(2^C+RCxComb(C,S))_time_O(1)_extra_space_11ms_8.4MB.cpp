class Solution {
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        const int FULL_MASK = (1 << COLS) - 1;
        
        int res = 0;
        for(int mask = 0; mask <= FULL_MASK; ++mask){
            int distinctCols = __builtin_popcount((unsigned int)mask);
            if(distinctCols != numSelect){
                continue;
            }
            
            int coveredRows = 0;
            for(int row = 0; row < ROWS; ++row){
                bool isCovered = true;
                for(int col = 0; col < COLS; ++col){
                    if(matrix[row][col] == 1){
                        if(((mask >> col) & 1) == 0){
                            isCovered = false;
                            break;
                        }
                    }
                }
                if(isCovered){
                    coveredRows += 1;
                }
            }
            
            res = max(res, coveredRows);
        }
        
        return res;
    }
};