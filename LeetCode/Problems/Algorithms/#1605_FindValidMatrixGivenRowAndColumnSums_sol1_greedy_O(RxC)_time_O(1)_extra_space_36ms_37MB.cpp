class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        const int ROWS = rowSum.size();
        const int COLS = colSum.size();

        vector<vector<int>> res(ROWS, vector<int>(COLS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                res[row][0] = rowSum[row];
            }
        }

        for(int col = 0; col + 1 < COLS; ++col){
            long long sum = 0;
            for(int row = 0; row < ROWS; ++row){
                sum += res[row][col];
            }
            long long excess = sum - colSum[col];
            for(int row = 0; row < ROWS; ++row){
                long long x = min((long long)res[row][col], excess);
                res[row][col] -= x;
                res[row][col + 1] += x;
                excess -= x;
            }
        }

        return res;
    }
};