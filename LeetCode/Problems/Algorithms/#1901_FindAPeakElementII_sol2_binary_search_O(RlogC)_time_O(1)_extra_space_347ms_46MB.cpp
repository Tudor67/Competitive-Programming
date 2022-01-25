class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        const int ROWS = mat.size();
        const int COLS = mat[0].size();
        
        int l = 0;
        int r = COLS - 1;
        int maxRow = 0;
        while(l != r){
            int mid = (l + r) / 2;
            int maxVal = -1;
            for(int row = 0; row < ROWS; ++row){
                int currentMaxVal = max(mat[row][mid], mat[row][mid + 1]);
                if(currentMaxVal > maxVal){
                    maxVal = currentMaxVal;
                    maxRow = row;
                }
            }
            if(mat[maxRow][mid] < mat[maxRow][mid + 1]){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        
        return {maxRow, r};
    }
};