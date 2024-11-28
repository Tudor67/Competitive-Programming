class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();

        int res = 0;
        unordered_map<string, int> freq;
        string canonicalForm(COLS, '0');

        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                canonicalForm[col] = char('0' + (matrix[row][0] == matrix[row][col]));
            }
            freq[canonicalForm] += 1;
            res = max(res, freq[canonicalForm]);
        }

        return res;
    }
};