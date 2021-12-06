class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int ROWS, int COLS) {
        const int N = original.size();
        
        if(N != ROWS * COLS){
            return {};
        }
        
        vector<vector<int>> arr2D(ROWS, vector<int>(COLS));
        int idx = -1;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                arr2D[row][col] = original[++idx];
            }
        }
        
        return arr2D;
    }
};