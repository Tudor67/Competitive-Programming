class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        const int ROWS = mat.size();
        const int COLS = mat[0].size();

        int res = 0;
        vector<int> h(COLS);

        for(int row1 = 0; row1 < ROWS; ++row1){
            fill(h.begin(), h.end(), 0);
            for(int row2 = row1; row2 < ROWS; ++row2){
                for(int col = 0; col < COLS; ++col){
                    if(mat[row2][col] == 0){
                        h[col] = 0;
                    }else{
                        h[col] += 1;
                    }
                }

                int w = 0;
                for(int col = 0; col < COLS; ++col){
                    if(h[col] < row2 - row1 + 1){
                        w = 0;
                    }else{
                        w += 1;
                    }
                    res += w;
                }
            }
        }

        return res;
    }
};