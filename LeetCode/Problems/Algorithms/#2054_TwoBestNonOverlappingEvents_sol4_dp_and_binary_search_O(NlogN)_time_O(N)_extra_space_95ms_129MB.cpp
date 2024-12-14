class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        const int N = events.size();

        // sort events in increasing order of their start times
        sort(events.begin(), events.end());

        // dp[k][i]: max sum when we attend at most k events from events[i .. N - 1]
        vector<vector<int>> dp(3, vector<int>(N + 1));
        
        for(int k = 1; k <= 2; ++k){
            for(int i = N - 1; i >= 0; --i){
                int l = i + 1;
                int r = N;
                while(l != r){
                    int mid = (l + r) / 2;
                    if(events[i][1] >= events[mid][0]){
                        l = mid + 1;
                    }else{
                        r = mid;
                    }
                }

                dp[k][i] = max(dp[k][i + 1], events[i][2] + dp[k - 1][r]);
            }
        }

        return dp[2][0];
    }
};