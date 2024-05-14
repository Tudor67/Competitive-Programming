class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int K = 3;

        vector<vector<int>> vMax(ROWS, vector<int>(COLS));
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
                vMax[row][col] = grid[dq[col].back()][col];
            }
        }

        vector<vector<int>> res(ROWS - K + 1, vector<int>(COLS - K + 1));
        deque<int> w;
        for(int row = K - 1; row < ROWS; ++row){
            w.clear();
            for(int col = 0; col < COLS; ++col){
                while(!w.empty() && col - w.back() + 1 > K){
                    w.pop_back();
                }
                while(!w.empty() && vMax[row][w.front()] <= vMax[row][col]){
                    w.pop_front();
                }
                w.push_front(col);
                if(col >= K - 1){
                    res[row - K + 1][col - K + 1] = vMax[row][w.back()];
                }
            }
        }

        return res;
    }
};