class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        const int ROWS = rowSum.size();
        const int COLS = colSum.size();

        vector<vector<int>> res(ROWS, vector<int>(COLS));
        vector<int> remRowSum = rowSum;
        vector<int> remColSum = colSum;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                res[row][col] = min(remRowSum[row], remColSum[col]);
                remRowSum[row] -= res[row][col];
                remColSum[col] -= res[row][col];
            }
        }

        return res;
    }
};