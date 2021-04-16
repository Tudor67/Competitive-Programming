class Solution {
private:
    static bool incEndComp(const vector<int>& LHS, const vector<int>& RHS){
        return (LHS[1] < RHS[1]);
    }
    
public:
    int maxValue(vector<vector<int>>& events, int k) {
        const int N = events.size();
        
        sort(events.begin(), events.end(), incEndComp);
        
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
                int l = 0;
                int r = j;
                while(l != r){
                    int mid = (l + r + 1) / 2;
                    if(events[mid][1] < events[j][0]){
                        l = mid;
                    }else{
                        r = mid - 1;
                    }
                }
                int k = r;
                if(0 <= k && events[k][1] < events[j][0]){
                    dp[i][j] = max(prefMaxDP[i - 1][k] + events[j][2], dp[i][j]);
                }
                prefMaxDP[i][j] = max(prefMaxDP[i][j - 1], dp[i][j]);
            }
        }
        
        int answer = *max_element(dp[k].begin(), dp[k].end());
        
        return answer;
    }
};