class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        const int N = tasks.size();
        const int FULL_MASK = (1 << N) - 1;
        const int INF = 1e8;
        
        // dp[mask]: min sessions to solve tasks from mask
        vector<int> dp(FULL_MASK + 1, INF);
        dp[0] = 1;
        
        // maxRemainingTime[mask]: max remaining time when we solve tasks from mask in min number of sessions
        vector<int> maxRemainingTime(FULL_MASK + 1, 0);
        maxRemainingTime[0] = sessionTime;
        
        for(int mask = 1; mask <= FULL_MASK; ++mask){
            for(int bit = 0; bit < N; ++bit){
                if((mask >> bit) & 1){
                    int prevMask = mask ^ (1 << bit);
                    if(maxRemainingTime[prevMask] < tasks[bit]){
                        if(dp[prevMask] + 1 < dp[mask]){
                            maxRemainingTime[mask] = sessionTime - tasks[bit];
                            dp[mask] = 1 + dp[prevMask];
                        }else if(dp[prevMask] + 1 == dp[mask]){
                            maxRemainingTime[mask] = max(maxRemainingTime[mask], maxRemainingTime[prevMask] - tasks[bit]);
                        }
                    }else{
                        if(dp[prevMask] < dp[mask]){
                            maxRemainingTime[mask] = maxRemainingTime[prevMask] - tasks[bit];
                            dp[mask] = dp[prevMask];
                        }else if(dp[prevMask] == dp[mask]){
                            maxRemainingTime[mask] = max(maxRemainingTime[mask], maxRemainingTime[prevMask] - tasks[bit]);
                        }
                    }
                }
            }
        }
        
        return dp[FULL_MASK];
    }
};