class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        const int N = numRows;
        vector<vector<int>> a(N);
        for(int row = 0; row <= N - 1; ++row){
            a[row].resize(row + 1);
            a[row][0] = 1;
            a[row][row] = 1;
            for(int col = 1; col <= row - 1; ++col){
                a[row][col] = a[row - 1][col - 1] + a[row - 1][col];
            }
        }
        return a;
    }
};