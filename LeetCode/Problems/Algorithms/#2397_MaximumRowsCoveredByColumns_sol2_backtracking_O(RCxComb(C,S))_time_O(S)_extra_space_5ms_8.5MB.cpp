class Solution {
private:
    void back(int level, int startCol, int takenColsMask, vector<vector<int>>& matrix, int numSelect, int& res){
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        
        if(level == numSelect){
            int coveredRows = 0;
            for(int row = 0; row < ROWS; ++row){
                bool isCovered = true;
                for(int col = 0; col < COLS; ++col){
                    if(matrix[row][col] == 1){
                        if(((takenColsMask >> col) & 1) == 0){
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
        }else{
            for(int col = startCol; col < COLS; ++col){
                back(level + 1, col + 1, takenColsMask | (1 << col), matrix, numSelect, res);
            }
        }
    }
    
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int res = 0;
        back(0, 0, 0, matrix, numSelect, res);
        return res;
    }
};