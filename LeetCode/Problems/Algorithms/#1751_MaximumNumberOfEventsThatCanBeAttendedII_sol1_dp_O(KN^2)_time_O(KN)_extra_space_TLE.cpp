class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        const int N = events.size();
        
        // dp[i][j]: max sum of values by attending maximum i events and the last attended event is events[j]
        vector<vector<int>> dp(k + 1, vector<int>(N, 0));
        
        for(int j = 0; j < N; ++j){
            dp[1][j] = events[j][2];
        }
        
        for(int i = 2; i <= k; ++i){
            for(int j = 0; j < N; ++j){
                dp[i][j] = dp[i - 1][j];
                for(int k = 0; k < N; ++k){
                    if(events[k][1] < events[j][0]){
                        dp[i][j] = max(dp[i - 1][k] + events[j][2], dp[i][j]);
                    }
                }
            }
        }
        
        int answer = *max_element(dp[k].begin(), dp[k].end());
        
        return answer;
    }
};