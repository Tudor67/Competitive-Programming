class Solution {
private:
    const long long INF = LLONG_MAX / 100;
    
    long long getDistance(long long pos1, long long pos2){
        return abs(pos1 - pos2);
    }
    
    long long getValue(vector<vector<vector<long long>>>& dp, int i, int j, int k){
        if(j < 0 || k < 0){
            return INF;
        }
        if(i < 0){
            return 0;
        }
        return dp[i][j][k];
    }
    
public:
    long long minimumTotalDistance(vector<int>& r, vector<vector<int>>& f) {
        const int R = r.size();
        const int F = f.size();
        
        sort(r.begin(), r.end());
        sort(f.begin(), f.end());
        
        // At iteration i:
        // dp[i % 2][j][k]: min cost (== total distance)
        //                  to repair sorted robots r[0 .. i] at sorted factories f[0 .. j]
        //                  such that (the remaining limit of f[j]) >= k
        vector<vector<vector<long long>>> dp(2, vector<vector<long long>>(F, vector<long long>(R + 1, INF)));
        for(int i = 0; i < R; ++i){
            for(int j = 0; j < F; ++j){
                for(int k = R; k >= 0; --k){
                    dp[i % 2][j][k] = INF;
                }
                
                // repair r[i] at f[0 .. j - 1]
                dp[i % 2][j][f[j][1]] = min(dp[i % 2][j][f[j][1]], getValue(dp, i % 2, j - 1, 0));
                
                // repair r[i] at f[j]
                for(int k = f[j][1] - 1; k >= 0; --k){
                    dp[i % 2][j][k] = min({dp[i % 2][j][k],
                                           dp[i % 2][j][k + 1],
                                           getValue(dp, (i - 1) % 2, j, k + 1) + getDistance(r[i], f[j][0])});
                }
            }
        }
        
        return dp[(R - 1) % 2][F - 1][0];
    }
};