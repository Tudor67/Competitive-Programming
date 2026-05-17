class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int N = matrix.size();

        // transpose
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < row; ++col){
                swap(matrix[row][col], matrix[col][row]);
            }
        }

        // reverse
        for(int row = 0; row < N; ++row){
            reverse(matrix[row].begin(), matrix[row].end());
        }
    }
};