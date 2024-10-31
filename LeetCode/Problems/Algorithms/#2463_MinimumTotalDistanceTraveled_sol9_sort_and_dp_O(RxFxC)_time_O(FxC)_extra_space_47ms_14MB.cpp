class Solution {
public:
    long long minimumTotalDistance(vector<int>& robots, vector<vector<int>>& factories) {
        const int R = robots.size();
        const int F = factories.size();
        const long long INF = 1e15;

        sort(robots.begin(), robots.end());
        sort(factories.begin(), factories.end());

        vector<int> singleFactories;
        for(int i = 0; i < F; ++i){
            singleFactories.resize(singleFactories.size() + factories[i][1], factories[i][0]);
        }

        const int SF = singleFactories.size();
        vector<vector<long long>> dp(2, vector<long long>(SF + 1, INF));
        fill(dp[R % 2].begin(), dp[R % 2].end(), 0);
        
        for(int i = R - 1; i >= 0; --i){
            dp[i % 2][SF] = INF;
            for(int j = SF - 1; j >= 0; --j){
                dp[i % 2][j] = min(dp[i % 2][j + 1],
                                   abs(robots[i] - singleFactories[j]) + dp[(i + 1) % 2][j + 1]);
            }
        }

        return dp[0][0];
    }
};