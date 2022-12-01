class Solution {
private:
    long long getDistance(long long pos1, long long pos2){
        return abs(pos1 - pos2);
    }
    
public:
    long long minimumTotalDistance(vector<int>& r, vector<vector<int>>& f) {
        const int R = r.size();
        const int F = f.size();
        const long long INF = LLONG_MAX / 100;
        
        sort(r.begin(), r.end());
        sort(f.begin(), f.end());
        
        vector<int> l;
        l.reserve(F * R);
        for(const vector<int>& FACTORY: f){
            int pos = FACTORY[0];
            int limit = FACTORY[1];
            l.resize(l.size() + limit, pos);
        }
        
        // dp[i][j]: min cost (== total distance)
        //           to repair sorted robots r[0 .. i] at sorted locations l[0 .. j]
        const int L = l.size();
        vector<vector<long long>> dp(R, vector<long long>(L, INF));
        
        dp[0][0] = getDistance(r[0], l[0]);
        for(int j = 1; j < L; ++j){
            dp[0][j] = min(dp[0][j - 1], getDistance(r[0], l[j]));
        }
        
        for(int i = 1; i < R; ++i){
            for(int j = i; j < L; ++j){
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1] + getDistance(r[i], l[j]));
            }
        }
        
        return dp[R - 1][L - 1];
    }
};