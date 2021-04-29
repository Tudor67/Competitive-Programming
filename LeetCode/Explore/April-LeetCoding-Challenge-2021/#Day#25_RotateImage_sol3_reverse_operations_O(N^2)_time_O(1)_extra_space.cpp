class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int N = matrix.size();
        // reverse the matrix around the middle column
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < N / 2; ++col){
                swap(matrix[row][col], matrix[row][N - 1 - col]);
            }
        }
        // reverse the matrix around the secondary diagonal
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < N - 1 - row; ++col){
                swap(matrix[row][col], matrix[N - 1 - col][N - 1 - row]);
            }
        }
    }
};