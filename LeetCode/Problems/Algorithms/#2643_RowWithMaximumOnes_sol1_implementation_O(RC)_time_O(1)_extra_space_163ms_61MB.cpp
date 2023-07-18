class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        const int ROWS = mat.size();
        
        int maxRow = 0;
        int maxRowOnes = count(mat[0].begin(), mat[0].end(), 1);
        
        for(int row = 1; row < ROWS; ++row){
            int rowOnes = count(mat[row].begin(), mat[row].end(), 1);
            if(rowOnes > maxRowOnes){
                maxRow = row;
                maxRowOnes = rowOnes;
            }
        }
        
        return {maxRow, maxRowOnes};
    }
};