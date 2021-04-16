class Solution {
private:
    static bool incEndComp(const vector<int>& LHS, const vector<int>& RHS){
        return (LHS[1] < RHS[1]);
    }
    
public:
    int maxValue(vector<vector<int>>& events, int k) {
        const int N = events.size();
        
        sort(events.begin(), events.end(), incEndComp);
        
        const int EVENT_START = 0;
        const int EVENT_END = 1;
        set<tuple<int, int, int>> timeTypeIdxSet;
        for(int j = 0; j < N; ++j){
            timeTypeIdxSet.insert({events[j][0], EVENT_START, j});
            timeTypeIdxSet.insert({events[j][1], EVENT_END, j});
        }
        
        // closestLeftEventIdx[eventStartTime] = maximum k, such that events[k][1] < eventStartTime
        unordered_map<int, int> closestLeftEventIdx;
        int prevIdx = 0;
        for(const tuple<int, int, int>& T: timeTypeIdxSet){
            int eventTime, eventType, eventIdx;
            tie(eventTime, eventType, eventIdx) = T;
            if(eventType == EVENT_START){
                closestLeftEventIdx[eventTime] = prevIdx;
            }else{
                prevIdx = eventIdx;
            }
        }
        
        // dp[i][j]: max sum of values by attending maximum i events and the last attended event is events[j]
        vector<vector<int>> dp(k + 1, vector<int>(N, 0));
        
        // prefMaxDP[i][j]: max sum of values by attending maximum i events and the last attended event is from events[0..j]
        // prefMaxDP[i][j] = max({dp[i][0], dp[i][1], dp[i][2], ..., dp[i][j]})
        vector<vector<int>> prefMaxDP(k + 1, vector<int>(N, 0));
        
        dp[1][0] = events[0][2];
        prefMaxDP[1][0] = events[0][2];
        for(int j = 1; j < N; ++j){
            dp[1][j] = events[j][2];
            prefMaxDP[1][j] = max(prefMaxDP[1][j - 1], dp[1][j]);
        }
        
        for(int i = 2; i <= k; ++i){
            copy(dp[i - 1].begin(), dp[i - 1].end(), dp[i].begin());
            copy(prefMaxDP[i - 1].begin(), prefMaxDP[i - 1].end(), prefMaxDP[i].begin());
            for(int j = i - 1; j < N; ++j){
                int k = closestLeftEventIdx[events[j][0]];
                if(events[k][1] < events[j][0]){
                    dp[i][j] = max(prefMaxDP[i - 1][k] + events[j][2], dp[i][j]);
                }
                prefMaxDP[i][j] = max(prefMaxDP[i][j - 1], dp[i][j]);
            }
        }
        
        int answer = *max_element(dp[k].begin(), dp[k].end());
        
        return answer;
    }
};