class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int N = matrix.size();
        
        for(int row1 = 0, row2 = N - 1; row1 < row2; ++row1, --row2){
            for(int col = 0; col < N; ++col){
                swap(matrix[row1][col], matrix[row2][col]);
            }
        }
        
        for(int row = 0; row < N; ++row){
            for(int col = row + 1; col < N; ++col){
                swap(matrix[row][col], matrix[col][row]);
            }
        }
    }
};