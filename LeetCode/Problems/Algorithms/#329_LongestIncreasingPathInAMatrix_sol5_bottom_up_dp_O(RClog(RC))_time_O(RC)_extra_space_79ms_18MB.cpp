class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        static const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        
        vector<tuple<int, int, int>> v;
        v.reserve(ROWS * COLS);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                v.emplace_back(matrix[row][col], row, col);
            }
        }
        
        sort(v.begin(), v.end());
        
        int res = 0;
        vector<vector<int>> maxLen(ROWS, vector<int>(COLS, 1));
        for(const tuple<int, int, int>& T: v){
            int row = get<1>(T);
            int col = get<2>(T);
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                    if(matrix[row][col] < matrix[nextRow][nextCol]){
                        maxLen[nextRow][nextCol] = max(maxLen[nextRow][nextCol], maxLen[row][col] + 1);
                    }
                }
            }
            res = max(res, maxLen[row][col]);
        }
        
        return res;
    }
};