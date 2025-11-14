class Solution {
public:
    vector<vector<int>> rangeAddQueries(int N, vector<vector<int>>& queries) {
        vector<vector<int>> res(N, vector<int>(N));

        for(vector<int>& query: queries){
            int row1 = query[0];
            int col1 = query[1];
            int row2 = query[2];
            int col2 = query[3];

            res[row1][col1] += 1;
            if(col2 + 1 < N){
                res[row1][col2 + 1] -= 1;
            }
            if(row2 + 1 < N){
                res[row2 + 1][col1] -= 1;
            }
            if(row2 + 1 < N && col2 + 1 < N){
                res[row2 + 1][col2 + 1] += 1;
            }
        }

        for(int row = 0; row < N; ++row){
            for(int col = 1; col < N; ++col){
                res[row][col] += res[row][col - 1];
            }
        }

        for(int col = 0; col < N; ++col){
            for(int row = 1; row < N; ++row){
                res[row][col] += res[row - 1][col];
            }
        }

        return res;
    }
};