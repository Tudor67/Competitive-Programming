class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int K = 3;

        vector<vector<int>> res(ROWS - K + 1, vector<int>(COLS - K + 1));
        vector<deque<int>> dq(COLS);

        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                while(!dq[col].empty() && row - dq[col].back() + 1 > K){
                    dq[col].pop_back();
                }
                while(!dq[col].empty() && grid[dq[col].front()][col] <= grid[row][col]){
                    dq[col].pop_front();
                }
                dq[col].push_front(row);

                if(row >= K - 1 && col >= K - 1){
                    int maxVal = grid[row][col];
                    for(int j = col; j >= col - K + 1; --j){
                        maxVal = max(maxVal, grid[dq[j].back()][j]);
                    }
                    res[row - K + 1][col - K + 1] = maxVal;
                }
            }
        }

        return res;
    }
};