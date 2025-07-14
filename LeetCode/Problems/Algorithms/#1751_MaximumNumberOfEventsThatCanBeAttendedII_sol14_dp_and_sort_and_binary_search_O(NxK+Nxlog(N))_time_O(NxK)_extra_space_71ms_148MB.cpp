class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        const int N = events.size();

        vector<array<int, 3>> sortedEvents(N);
        for(int i = 0; i < N; ++i){
            sortedEvents[i] = {events[i][0], events[i][1], events[i][2]};
        }

        sort(sortedEvents.begin(), sortedEvents.end());

        vector<int> nxt(N, N);
        for(int i = N - 1; i >= 0; --i){
            int l = i + 1;
            int r = N;
            while(l != r){
                int mid = (l + r) / 2;
                if(sortedEvents[i][1] >= sortedEvents[mid][0]){
                    l = mid + 1;
                }else{
                    r = mid;
                }
            }
            nxt[i] = r;
        }

        // dp[k][i]: max value we can receive when we attend at most k events from sortedEvents[i .. 0]
        vector<vector<int>> dp(k + 1, vector<int>(N + 1));
        for(int a = 1; a <= k; ++a){
            for(int i = N - 1; i >= 0; --i){
                dp[a][i] = max(dp[a][i + 1], sortedEvents[i][2] + dp[a - 1][nxt[i]]);
            }
        }

        return dp[k][0];
    }
};