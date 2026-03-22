class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        vector<vector<int>> res(ROWS - k + 1, vector<int>(COLS - k + 1));
        vector<int> v;

        for(int startRow = 0; startRow + k - 1 < ROWS; ++startRow){
            for(int startCol = 0; startCol + k - 1 < COLS; ++startCol){
                v.clear();
                for(int row = startRow; row < startRow + k; ++row){
                    for(int col = startCol; col < startCol + k; ++col){
                        v.push_back(grid[row][col]);
                    }
                }
                
                sort(v.begin(), v.end());
                v.resize(unique(v.begin(), v.end()) - v.begin());

                int minAbsDiff = INT_MAX;
                for(int i = 1; i < (int)v.size(); ++i){
                    minAbsDiff = min(minAbsDiff, v[i] - v[i - 1]);
                }

                if(minAbsDiff == INT_MAX){
                    minAbsDiff = 0;
                }
                
                res[startRow][startCol] = minAbsDiff;
            }
        }

        return res;
    }
};