class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        const int ROWS = mat.size();
        const int COLS = mat[0].size();

        vector<vector<int>> diagValues(ROWS + COLS - 1);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                diagValues[row + col].push_back(mat[row][col]);
            }
        }

        vector<int> res;
        res.reserve(ROWS * COLS);
        for(int i = 0; i < (int)diagValues.size(); ++i){
            if(i % 2 == 0){
                reverse(diagValues[i].begin(), diagValues[i].end());
            }
            copy(diagValues[i].begin(), diagValues[i].end(), back_inserter(res));
        }

        return res;
    }
};