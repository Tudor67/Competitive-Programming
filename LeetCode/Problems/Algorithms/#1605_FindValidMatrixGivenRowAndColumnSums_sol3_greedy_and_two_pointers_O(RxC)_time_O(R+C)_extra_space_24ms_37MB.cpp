class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        const int ROWS = rowSum.size();
        const int COLS = colSum.size();

        vector<vector<int>> res(ROWS, vector<int>(COLS));
        vector<int> remRowSum = rowSum;
        vector<int> remColSum = colSum;

        int row = 0;
        int col = 0;
        while(row < ROWS && col < COLS){
            res[row][col] = min(remRowSum[row], remColSum[col]);
            remRowSum[row] -= res[row][col];
            remColSum[col] -= res[row][col];
            if(remRowSum[row] == 0){
                row += 1;
            }else{
                col += 1;
            }
        }

        return res;
    }
};