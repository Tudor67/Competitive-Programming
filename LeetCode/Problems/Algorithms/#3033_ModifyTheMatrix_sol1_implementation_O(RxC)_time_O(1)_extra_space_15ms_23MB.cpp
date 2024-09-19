class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        
        vector<vector<int>> res = matrix;
        for(int col = 0; col < COLS; ++col){
            int maxVal = -1;
            for(int row = 0; row < ROWS; ++row){
                maxVal = max(maxVal, matrix[row][col]);
            }
            for(int row = 0; row < ROWS; ++row){
                if(res[row][col] == -1){
                    res[row][col] = maxVal;
                }
            }
        }
        
        return res;
    }
};