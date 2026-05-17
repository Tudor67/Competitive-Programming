class Solution {
private:
    long long getColSum(vector<long long>& suffSum, int firstRow, int lastRow){
        if(firstRow > lastRow){
            return 0;
        }
        return suffSum[firstRow] - suffSum[lastRow + 1];
    }

    void maximize(long long& a, long long b){
        a = max(a, b);
    }

public:
    long long maximumScore(vector<vector<int>>& grid) {
        const int N = grid.size();

        vector<vector<long long>> suffSumOfCol(N, vector<long long>(N + 1));
        for(int row = N - 1; row >= 0; --row){
            for(int col = 0; col < N; ++col){
                suffSumOfCol[col][row] = grid[row][col] + suffSumOfCol[col][row + 1];
            }
        }

        // dp[i][r1][r0]: max score considering columns [0 .. i]
        //                where:
        //                  - column (i - 1) has its first r1 rows black
        //                  - column (i)     has its first r0 rows black
        vector<vector<vector<long long>>> dp(N, vector<vector<long long>>(N + 1, vector<long long>(N + 1)));

        for(int i = 1; i < N; ++i){
            for(int r0 = 0; r0 <= N; ++r0){
                for(int r1 = 0; r1 <= N; ++r1){
                    for(int r2 = 0; r2 <= N; ++r2){
                        if(r1 > r0){
                            maximize(dp[i][r1][r0], dp[i - 1][r2][r1] + getColSum(suffSumOfCol[i], r0, r1 - 1));
                        }else if(r2 > r0){
                            maximize(dp[i][r1][r0], dp[i - 1][r2][r1]);
                        }else{
                            maximize(dp[i][r1][r0], dp[i - 1][r2][r1] - getColSum(suffSumOfCol[i - 1], r1, r2 - 1)
                                                                      + getColSum(suffSumOfCol[i - 1], r1, r0 - 1));
                        }
                    }
                }
            }
        }

        long long res = 0;
        for(int r0 = 0; r0 <= N; ++r0){
            for(int r1 = 0; r1 <= N; ++r1){
                res = max(res, dp[N - 1][r1][r0]);
            }
        }

        return res;
    }
};