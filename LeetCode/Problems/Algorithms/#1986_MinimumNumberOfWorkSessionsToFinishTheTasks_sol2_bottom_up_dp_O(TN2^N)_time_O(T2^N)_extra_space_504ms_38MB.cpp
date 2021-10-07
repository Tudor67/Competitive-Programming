class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        const int N = tasks.size();
        const int FULL_MASK = (1 << N) - 1;
        const int INF = 1e8;
        
        // dp[mask][remTime]: min sessions to solve tasks from mask with remTime remaining time
        vector<vector<int>> dp(FULL_MASK + 1, vector<int>(sessionTime + 1, INF));
        dp[0][sessionTime] = 1;
        for(int mask = 0; mask <= FULL_MASK; ++mask){
            for(int bit = 0; bit < N; ++bit){
                if((mask >> bit) & 1){
                    int prevMask = mask ^ (1 << bit);
                    for(int prevRemainingTime = 0; prevRemainingTime <= sessionTime; ++prevRemainingTime){
                        if(prevRemainingTime < tasks[bit]){
                            int remainingTime = sessionTime - tasks[bit];
                            dp[mask][remainingTime] = min(dp[mask][remainingTime], 1 + dp[prevMask][prevRemainingTime]);
                        }else{
                            int remainingTime = prevRemainingTime - tasks[bit];
                            dp[mask][remainingTime] = min(dp[mask][remainingTime], dp[prevMask][prevRemainingTime]);
                        }
                    }
                }
            }
        }
        
        return *min_element(dp[FULL_MASK].begin(), dp[FULL_MASK].end());
    }
};