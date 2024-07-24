class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        const int INF = 1e9;
        
        int maxOfRowMins = -INF;
        for(int row = 0; row < ROWS; ++row){
            int rowMin = matrix[row][0];
            for(int col = 0; col < COLS; ++col){
                rowMin = min(rowMin, matrix[row][col]);
            }
            maxOfRowMins = max(maxOfRowMins, rowMin);
        }

        int minOfColMaxs = INF;
        for(int col = 0; col < COLS; ++col){
            int colMax = matrix[0][col];
            for(int row = 0; row < ROWS; ++row){
                colMax = max(colMax, matrix[row][col]);
            }
            minOfColMaxs = min(minOfColMaxs, colMax);
        }

        if(maxOfRowMins == minOfColMaxs){
            return {maxOfRowMins};
        }

        return {};
    }
};