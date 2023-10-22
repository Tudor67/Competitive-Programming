class Solution {
public:
    vector<int> getRow(int rowIndex) {
        const int N = rowIndex;

        vector<vector<int>> a(2, vector<int>(N + 1));
        for(int row = 0; row <= N; ++row){
            a[row % 2][0] = 1;
            a[row % 2][row] = 1;
            for(int col = 1; col <= row - 1; ++col){
                a[row % 2][col] = a[(row - 1) % 2][col - 1] + a[(row - 1) % 2][col];
            }
        }

        return a[N % 2];
    }
};