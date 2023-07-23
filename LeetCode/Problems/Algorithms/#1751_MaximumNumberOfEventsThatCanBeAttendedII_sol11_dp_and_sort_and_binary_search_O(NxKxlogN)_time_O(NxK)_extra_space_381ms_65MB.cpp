class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        const int N = events.size();

        using Event = array<int, 3>;
        vector<Event> sortedEvents(N);
        for(int i = 0; i < N; ++i){
            sortedEvents[i] = {events[i][0], events[i][1], events[i][2]};
        }

        sort(sortedEvents.begin(), sortedEvents.end(),
             [](const Event& LHS, const Event& RHS){
                 return (LHS[1] < RHS[1]);
             });

        // dp[i][j]: max sum when attending max j events from sortedEvents[0 .. i]
        vector<vector<int>> dp(N, vector<int>(k + 1));
        dp[0][1] = sortedEvents[0][2];
        for(int i = 1; i < N; ++i){
            dp[i][1] = max(dp[i - 1][1], sortedEvents[i][2]);
        }

        for(int j = 2; j <= k; ++j){
            dp[0][j] = dp[0][j - 1];
            for(int i = 1; i < N; ++i){
                int l = 0;
                int r = i - 1;
                while(l != r){
                    int mid = (l + r + 1) / 2;
                    if(sortedEvents[mid][1] < sortedEvents[i][0]){
                        l = mid;
                    }else{
                        r = mid - 1;
                    }
                }

                int prevIndex = r;
                if(sortedEvents[prevIndex][1] < sortedEvents[i][0]){
                    dp[i][j] = max(dp[i][j], dp[prevIndex][j - 1] + sortedEvents[i][2]);
                }
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
        }

        return dp[N - 1][k];
    }
};