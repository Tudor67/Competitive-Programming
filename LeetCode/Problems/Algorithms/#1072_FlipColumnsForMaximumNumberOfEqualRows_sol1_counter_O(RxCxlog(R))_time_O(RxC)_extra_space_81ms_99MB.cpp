class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();

        int res = 0;
        map<vector<int>, int> freq;
        for(int row = 0; row < ROWS; ++row){
            vector<vector<int>> flips(2);
            for(int col = 0; col < COLS; ++col){
                flips[matrix[row][col]].push_back(col);
            }
            freq[flips[0]] += 1;
            freq[flips[1]] += 1;
            res = max(res, max(freq[flips[0]], freq[flips[1]]));
        }

        return res;
    }
};