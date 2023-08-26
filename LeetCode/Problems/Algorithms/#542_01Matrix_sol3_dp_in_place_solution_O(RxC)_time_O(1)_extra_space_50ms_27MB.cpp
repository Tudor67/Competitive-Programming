class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        const int ROWS = mat.size();
        const int COLS = mat[0].size();
        const int INF = 1e9;

        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(mat[row][col] == 1){
                    mat[row][col] = INF;
                }
            }
        }

        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(mat[row][col] > 0){
                    if(row - 1 >= 0){
                        mat[row][col] = min(mat[row][col], mat[row - 1][col] + 1);
                    }
                    if(col - 1 >= 0){
                        mat[row][col] = min(mat[row][col], mat[row][col - 1] + 1);
                    }
                }
            }
        }

        for(int row = ROWS - 1; row >= 0; --row){
            for(int col = COLS - 1; col >= 0; --col){
                if(mat[row][col] > 0){
                    if(row + 1 < ROWS){
                        mat[row][col] = min(mat[row][col], mat[row + 1][col] + 1);
                    }
                    if(col + 1 < COLS){
                        mat[row][col] = min(mat[row][col], mat[row][col + 1] + 1);
                    }
                }
            }
        }

        return mat;
    }
};