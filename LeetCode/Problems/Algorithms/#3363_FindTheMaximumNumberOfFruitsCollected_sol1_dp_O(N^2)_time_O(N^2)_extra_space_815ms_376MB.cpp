class Solution {
private:
    void applyDPAndUpdateResult(vector<vector<int>>& fruits, int srcRow, int srcCol,
                                const vector<pair<int, int>>& DIRECTIONS, int& res){
        const int N = fruits.size();
        const int INF = 1e9;

        vector<vector<int>> dist(N, vector<int>(N, INF));
        vector<vector<int>> dp(N, vector<int>(N, -1));
        queue<pair<int, int>> q;
        q.push({srcRow, srcCol});
        dist[srcRow][srcCol] = 0;
        dp[srcRow][srcCol] = fruits[srcRow][srcCol];

        for(int step = 1; step <= N - 1; ++step){
            for(int i = q.size(); i >= 1; --i){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for(const auto& [rowDir, colDir]: DIRECTIONS){
                    int nextRow = row + rowDir;
                    int nextCol = col + colDir;
                    if(min(nextRow, nextCol) >= 0 && max(nextRow, nextCol) < N){
                        if(dist[row][col] + 1 <= dist[nextRow][nextCol] &&
                           dp[nextRow][nextCol] < dp[row][col] + fruits[nextRow][nextCol]){
                            dist[nextRow][nextCol] = dist[row][col] + 1;
                            dp[nextRow][nextCol] = dp[row][col] + fruits[nextRow][nextCol];
                            q.push({nextRow, nextCol});
                        }
                    }
                }
            }
        }

        int row = N - 1;
        int col = N - 1;
        while(row != srcRow || col != srcCol){
            fruits[row][col] = 0;
            for(const auto& [rowDir, colDir]: DIRECTIONS){
                int prevRow = row - rowDir;
                int prevCol = col - colDir;
                if(min(prevRow, prevCol) >= 0 && max(prevRow, prevCol) < N &&
                   dist[prevRow][prevCol] + 1 == dist[row][col]){
                    row = prevRow;
                    col = prevCol;
                }
            }
        }
        fruits[srcRow][srcCol] = 0;

        res += dp[N - 1][N - 1];
    }

public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        const int N = fruits.size();

        int res = 0;
        vector<vector<int>> remFruits = fruits;
        applyDPAndUpdateResult(remFruits, 0, 0, {{0, 1}, {1, 0}, {1, 1}}, res);
        applyDPAndUpdateResult(remFruits, 0, N - 1, {{1, -1}, {1, 0}, {1, 1}}, res);
        applyDPAndUpdateResult(remFruits, N - 1, 0, {{-1, 1}, {0, 1}, {1, 1}}, res);

        return res;
    }
};