class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        const int ROWS = mat.size();
        const int COLS = mat[0].size();
        
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(mat[row][col] != mat[row][(col + k) % COLS]){
                    return false;
                }
            }
        }

        return true;
    }
};