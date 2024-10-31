class Solution {
private:
    void minimize(long long& a, long long b){
        a = min(a, b);
    }

public:
    long long minimumTotalDistance(vector<int>& robots, vector<vector<int>>& factories) {
        const int R = robots.size();
        const int F = factories.size();
        const long long INF = 1e15;

        sort(robots.begin(), robots.end());
        sort(factories.begin(), factories.end());

        int maxFactoryCapacity = 0;
        for(int i = 0; i < F; ++i){
            maxFactoryCapacity = max(maxFactoryCapacity, factories[i][1]);
        }
        
        vector<vector<vector<long long>>> dp(R + 1, vector<vector<long long>>(F,
                                             vector<long long>(maxFactoryCapacity + 1, INF)));
        for(int f = 0; f < F; ++f){
            for(int c = 0; c <= maxFactoryCapacity; ++c){
                dp[R][f][c] = 0;
            }
        }

        for(int r = R - 1; r >= 0; --r){
            for(int f = F - 1; f >= 0; --f){
                for(int c = 0; c <= factories[f][1]; ++c){
                    if(f + 1 < F){
                        minimize(dp[r][f][c], dp[r][f + 1][factories[f + 1][1]]);
                    }
                    if(c >= 1){
                        minimize(dp[r][f][c], abs(robots[r] - factories[f][0]) + dp[r + 1][f][c - 1]);
                    }
                }
            }
        }

        return dp[0][0][factories[0][1]];
    }
};