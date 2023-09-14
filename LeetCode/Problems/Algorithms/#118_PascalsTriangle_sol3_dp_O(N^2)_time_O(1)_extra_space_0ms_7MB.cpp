class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> a(numRows);
        for(int row = 0; row < numRows; ++row){
            a[row].resize(row + 1, 1);
            for(int col = 1; col < row; ++col){
                a[row][col] = a[row - 1][col - 1] + a[row - 1][col];
            }
        }
        return a;
    }
};