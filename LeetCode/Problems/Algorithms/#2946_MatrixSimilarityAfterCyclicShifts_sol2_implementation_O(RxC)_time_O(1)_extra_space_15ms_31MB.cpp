class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        const int ROWS = mat.size();
        const int COLS = mat[0].size();

        k %= COLS;
        
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                int nextCol = (col + (row % 2 == 0 ? k : -k) + COLS) % COLS;
                if(mat[row][col] != mat[row][nextCol]){
                    return false;
                }
            }
        }

        return true;
    }
};