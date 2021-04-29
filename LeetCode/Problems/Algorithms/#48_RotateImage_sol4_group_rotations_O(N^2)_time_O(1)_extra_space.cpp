class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int N = matrix.size();
        for(int row = 0; row < N / 2; ++row){
            for(int col = 0; col < (N + 1) / 2; ++col){
                int temp = matrix[row][col];
                matrix[row][col] = matrix[N - 1 - col][row];
                matrix[N - 1 - col][row] = matrix[N - 1 - row][N - 1 - col];
                matrix[N - 1 - row][N - 1 - col] = matrix[col][N - 1 - row];
                matrix[col][N - 1 - row] = temp;
            }
        }
    }
};