class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int ROWS, int COLS) {
        const int N = original.size();
        
        if(N != ROWS * COLS){
            return {};
        }
        
        vector<vector<int>> arr2D(ROWS, vector<int>(COLS));
        for(int i = 0; i < N; ++i){
            int row = i / COLS;
            int col = i % COLS;
            arr2D[row][col] = original[i];
        }
        
        return arr2D;
    }
};