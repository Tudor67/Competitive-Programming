class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        const int N = intervals.size();

        // sortedIntervals: intervals sorted in increasing order of startTime
        vector<array<int, 2>> sortedIntervals(N);
        for(int i = 0; i < N; ++i){
            sortedIntervals[i] = {intervals[i][0], intervals[i][1]};
        }

        sort(sortedIntervals.begin(), sortedIntervals.end());

        // dp[i]: min cost to make sortedIntervals[i .. N - 1] non-overlapping
        vector<int> dp(N + 1);
        for(int i = N - 2; i >= 0; --i){
            int endTime = sortedIntervals[i][1];
            int j = lower_bound(sortedIntervals.begin() + i + 1, sortedIntervals.end(), array<int, 2>{endTime, endTime})
                    - sortedIntervals.begin();
            int removeCost = 1 + dp[i + 1];
            int keepCost = j - i - 1 + dp[j];
            dp[i] = min(removeCost, keepCost);
        }

        return dp[0];
    }
};